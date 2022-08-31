#include <iostream>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

// I avoid the use of boost library by creating the to_string method inside the std library.
std::string to_string( int x ) {
    int length = snprintf( NULL, 0, "%d", x );
    assert( length >= 0 );
    char* buf = new char[length + 1];
    snprintf( buf, length + 1, "%d", x );
    std::string str( buf );
    delete[] buf;
    return str;
}

// Open-Close Principle: Objects or entities should be open for extension but closed for modification. 
// This means that a class should be extendable without modifying the class itself.
// Enterprise Pattern

// we create a product with color and size
enum class Color { red, green, blue};
enum class Size { small, medium, large};

struct Product {
    string name;
    Color color; 
    Size size;
};

// 1. first solution: we create a product filter class with a method for each filter
//    This solution does not achieve the Open-Close Principle because 
//    for any new filter we have to modify this class. 
struct ProductFilter {

    /**
     * @brief function that filter by color
     * 
     * @param items 
     * @param color 
     * @return vector<Product*> 
     */
    vector<Product*> by_color(vector<Product*> items, Color color) {
        vector<Product*> result;
        for(auto& i: items){
            if (i->color == color){
                result.push_back(i);
            }
        }
        return result;
    }

    /**
     * @brief function that filter by size
     * 
     * @param items 
     * @param size 
     * @return vector<Product*> 
     */
    vector<Product*> by_size(vector<Product*> items, Size size) {
        vector<Product*> result;
        for(auto& i: items){
            if (i->size == size){
                result.push_back(i);
            }
        }
        return result;
    }
    
    /**
     * @brief function that filter by size and color
     * 
     * @param items 
     * @param size 
     * @param color 
     * @return vector<Product*> 
     */
    vector<Product*> by_size_and_color(vector<Product*> items, Size size, Color color) {
        vector<Product*> result;
        for(auto& i: items){
            if (i->size == size && i->color == color){
                result.push_back(i);
            }
        }
        return result;
    }
};

// 2. second solution that applies the Open-Close Principle
//   We create some Specifications that need to be true
template <typename T> struct AndSpecification;

template <typename T> struct Specification
{  
    virtual ~Specification() = default;
    virtual bool is_satisfied(T* item) const = 0;
};

// To simplify, we override the and operator
template <typename T> AndSpecification<T> operator&&
  (const Specification<T>& first, const Specification<T>& second)
{
  return { first, second };
}

// we create an interface Filter
template <typename T> struct Filter
{
    /* data */
    virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;
};

// implement the interface
struct BetterFilter : Filter<Product>
{
    vector<Product*> filter(vector<Product *> items, Specification<Product> &spec) override {
        vector<Product*> result;
        for (auto& item : items){
            if (spec.is_satisfied(item)){
                result.push_back(item);
            }
        }
        return result;
    }
};

// we create the ColorSpecification filter
struct ColorSpecification : Specification<Product> {

    Color color; 

    ColorSpecification(Color color) : color(color) {}

    bool is_satisfied(Product* item) const override {
        return item->color == color;
    }

};

// we create the SizeSpecification filter
struct SizeSpecification : Specification<Product> {

    Size size; 

    SizeSpecification(Size size) : size(size) {}

    bool is_satisfied(Product* item) const override {
        return item->size == size;
    }

};

// implement the combined filters
template <typename T> struct AndSpecification : Specification<T> {

    const Specification<T>& first;
    const Specification<T>& second;

    AndSpecification(const Specification<T>& first, const Specification<T>& second) : first(first), second(second) {}

    bool is_satisfied(T *item) const override {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }

};



int main() {

    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    const vector<Product*> items { &apple, &tree, &house};

    BetterFilter bf;
    ColorSpecification green(Color::green);
    auto green_things = bf.filter(items, green);
    for (auto& x : green_things){
        cout << x->name << " is green\n";
    }
    
    SizeSpecification large(Size::large);
    AndSpecification<Product> green_and_large(green, large);

    //auto big_green_things = bf.filter(all, green_and_large);

    // use the operator instead (same for || etc.)
    auto spec_combine = green && large;
    for (auto& item : bf.filter(items, spec_combine)){
        cout << item->name << " is green and large" <<endl;
    }

    getchar();

    return 0;
}
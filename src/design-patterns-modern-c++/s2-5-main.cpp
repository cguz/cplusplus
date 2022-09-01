#include <iostream>
#include <cassert>
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

// Liskov Substitution Principle:
// Let q(x) be a property provable about objects of x of type T. 
// Then q(y) should be provable for objects y of type S where S is a subtype of T.

// we create a class with some virtual methods that can be overloaded. 
class Rectangle {
    protected:
        int width, height;
    public: 
        Rectangle(int width, int height) :width(width), height(height) {}

    int get_width() const { return width; }
    virtual void set_width(const int width) { this->width = width; }
    int get_height() const { return height; }
    virtual void set_height(const int height) { this->height = height; }

    int area() const { return width * height; } 
};

// create the class Square that extends the functionality of Rectangle
// this class override the methods get_width and get_height
class Square : public Rectangle
{
  public:
    Square(int size): Rectangle(size,size) {}

    void set_width(const int width) override {
      this->width = height = width;
    }
    void set_height(const int height) override {
      this->height = width = height;
    }
};

// we should apply a Factory Pattern to create the Rectangle and the Square
struct RectangleFactory
{
  static Rectangle create_rectangle(int w, int h);
  static Rectangle create_square(int size);
};

void process(Rectangle& r)
{
  int w = r.get_width();
  r.set_height(10);

  std::cout << "expected area = " << (w * 10) 
    << ", got " << r.area() << std::endl;
}

int main()
{
  Rectangle r{ 5, 5 };
  process(r);

  Square s{ 5 };
  process(s);

  getchar();
  return 0;
}
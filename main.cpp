//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include <string>
#include "catch.hpp"
using Catch::Matchers::Equals;
//------------------------------
using namespace std;
// Fix the following class
class Complex {
  private:
  int a, bi;
  public:
    void operator>>(std::string&) const;
    void operator<<(const std::string&);
    Complex();
    Complex(int);
    Complex (int r=0, int img=0);
    int imagin(){ return this -> bi;}
    int re(){ return this -> a ;}
};

int Complex object (int rno, int img){
 rno= re ;
 img= imagin ;
}


void operator>> (std:string&r) const {
 r.append(std::to_string(this->re));
 if (this->imaginary > 0){
  r.append("+");}

 r.append(std::to_string(this->imagin));
 r.append("i");


}

void operator << (const std::string&r) {

}



//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Complex c;
        REQUIRE( c.re() == 0 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c2" ) {
        Complex c{1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c3" ) {
        Complex c{1,1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "o1" ) {
        Complex c; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("0+0i") );
    }
    SECTION( "o2" ) {
        Complex c{1, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("1+2i") );
    }
    SECTION( "o3" ) {
        Complex c{2, -2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("2-2i") );
    }
    SECTION( "o4" ) {
        Complex c{-2, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("-2+2i") );
    }
    SECTION( "p1" ) {
        Complex c;
        c << "1+1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "p2" ) {
        Complex c;
        c << "1-1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == -1 );
    }
    SECTION( "p3" ) {
        Complex c;
        c << "-1+0i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "p4" ) {
        Complex c;
        c << "-1-2i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == -2 );
    }
}
//------------------------------

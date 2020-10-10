# Constructor

클래스의 모든 멤버 변수가 모두 `public`인 경우 초기화 목록(initialization list) 또는 유니폼 초기화(uniform initialization)를 사용하여 직접 초기화가 가능하다.

그러나 멤버 변수가 `private`인 경우 변수에 직접 접근할 수 없기 때문에 위와 같은 방법으로는 클래스를 초기화할 수 없다. 

------

**Constructor(생성자)**는 해당 클래스의 객체가 인스턴스화될 때 자동으로 호출되는 특수한 종류의 멤버함수다. 생성자는 일반적으로 클래스의 멤버 변수를 적절한 기본값 또는 사용자 제공 값으로 초기화하거나 클래스를 사용하는 데 필요한 설정(e.g. 파일 열기)이 필요한 경우 사용된다.

일반적인 멤버 함수와 다르게 생성자 정의 방법에는 특정 규칙이 있다.

1. 생성자 이름은 클래스 이름과 같아야 한다.
2. 생성자는 리턴 타입이 없다.(void도 아니다.)

------



## 1. 기본 생성자(Default constructor)

매개변수를 갖지 않거나 기본값이 모두 설정된 매개변수를 가지고 있는 생성자를 **기본 생성자**라고 한다. 클래스를 인스턴스화할 때 사용자가 초기값을 제공하지 않으면 기본 생성자가 호출된다.

```c++
#include <iostream>

class Fraction {
    private:
    int m_numerator; // 분자
    int m_denominator; // 분모
    
    public:
    Fraction() { // default constructor
        m_numerator = 0;
        m_denominator = 1;
    }
    
    int getNumerator() {
        return m_numerator;
    }
    int getDenominator() {
        return m_denominator;
    }
    double getValue() {
        return static_cast<double>(m_numerator)/m_denominator;
    }
}

int main() {
    Fraction frac; // Since no arguments, calls Fraction() default constructor
    std::cout << frac.getNumerator() << "/" << frac.getDenominator() << "\n"; // Output : 0/1
    return 0;
};
```

위 예제는 분자와 분모 값을 가진 `Fraction`클래스가 있고, 클래스 이름과 같은 `Fraction()` 기본 생성자를 정의했다. 인수 없이  `Fraction` 타입의 객체를 인스턴스화 했으므로 객체에 메모리가 할당된 직후 기본 생성자가 호출되고 객체가 초기화된다.

분자와 분모 변수는 기본 생성자에서 지정된 값으로 초기화되었다. 이처럼 기본 생성자는 초기화되지 않은 변수들에 대해 쓰레기 값을 갖게 하지 않으므로 유용한 기능이다.

------



## 2. 매개변수가 있는 생성자를 이용한 초기화

기본 생성자는 클래스 멤버 변수의 기본값을 설정하는데 유용하지만, 클래스 인스턴스 별 멤버 변수의 값을 특정한 값으로 초기화하고 싶은 경우가 있다.

```cpp
#include <iostream>
#include <cassert>

class Fraction {
    private:
    int m_numerator;
    int m_denominator;
    
    public:
    Fraction() {
        m_numerator = 0;
        m_denominator = 1;
    }
    
    // Constructor with two parameters, one parameter having a default value
    Fraction(int numerator, int denominator = 1) {
        assert(denominator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }
    
    int getNumerator() {
        return m_numerator;
    }
    int getDenominator() {
        return m_denominator;
    }
    double getValue() {
        return static_cast<double>(m_numerator)/m_denominator;
    }
};
```

위 예제에는 한 클래스 안에 두 개의 생성자가 있다.

- 기본 경우에 호출될 기본 생성자
- 두 개의 매개변수를 사용하는 생성자

이 두 생성자는 함수 overload로 인해 같은 클래스 안에서 공존할 수 있다. 실제로 각각 고유한 서명(매개변수 개수 및 타입)으로 원하는 수만큼 생성자를 정의할 수 있다.
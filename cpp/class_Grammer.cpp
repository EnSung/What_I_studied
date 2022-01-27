#include <iostream> //전처리 지시자
#include <climits>
#include <cstring>
#include <string>



#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// 원래는 따로 cpp 파일을 만들어 함수 구현부를 따로 빼주는것이 편함

#pragma region 클래스

#pragma region Stock
class Stock
{
	// private : 외부에서 접근 불가, 외부에서 접근하기위해선 public으로 선언된 함수를 통해 값을 변경해야한다.
private:
	string name;
	int shares;
	float share_val;
	double total_val;
	void set_total() { total_val = shares * share_val; };

public:

	void buy(int, float);
	void sell(int, float);
	void update(float);
	void show();
	Stock& topval(Stock&);
	Stock(string co, int n, float pr);// 생성자가 생겼으니 디폴트 생성자도 만들어주어야함
	Stock();
	~Stock();

private:

};

// :: - 사용 범위결정 연산자  

void Stock::buy(int n, float pr) {// Stock클래스의 사용범위에 결정된다로 받아드려짐.
	shares += n;
	share_val = pr;
	set_total();

}
void Stock::sell(int n, float pr) {
	shares -= n;
	share_val = pr;
	set_total();
}
void Stock::update(float pr) {
	share_val = pr;
	set_total();
}
void Stock::show() {
	cout << "회사 명 : " << name << endl;
	cout << "주식 수 : " << shares << endl;
	cout << "주가 : " << share_val << endl;
	cout << "주식 총 가치 : " << total_val << endl;
}

// 생성자
Stock::Stock(string co, int n, float pr)
{
	name = co;
	shares = n;
	share_val = pr;
	set_total();
}


Stock& Stock::topval(Stock& s) {
	if (s.share_val > share_val) {
		return s;
	}
	else {
		return *this; // 자기 자신  this는 포인터기때문에 주소를 나타낸다. 그래서 *를 붙여 객체를 리턴해줌 
	}
}

Stock::Stock() {
	name = "";
	shares = 0;
	share_val = 0;
	set_total();
}

// 소멸자
Stock::~Stock()
{
	cout << name << "클래스가 소멸되었습니다.\n";
}
#pragma endregion

#pragma region Time


class Time
{ 
private:
	int hours;
	int mins;
public:
	void addHours(int);
	void addMins(int);
	//Time sum(Time&);
	Time operator+(Time&); // sum함수 이름을 operator+
	virtual void show();
	Time();
	Time(int,int);
	~Time();
	Time operator*(int);
	friend Time operator*(int, Time&); // 이 원형은 두가지 함축적인 의미를 가지고있다.
	// operator*는 클래스 안에 선언되었지만 멤버함수가 아니다. 그러므로 우리가 평소에 호출하기위해 썼던 "." 이나 "->"를 통해 호출할 수 없다.
	// 멤버함수는 아니지만 멤버함수와 동등한 접근 권한이 있다.
	
	friend std::ostream& operator<<(std::ostream&, Time&);

	int getHour() { return hours; }
	int getMins() { return mins; }

};

Time::Time()
{
	hours = mins = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	mins = m;
}
Time::~Time()
{
}

void Time::addHours(int h) {
	hours += h;
}
void Time::addMins(int m) {
	mins += m;
	hours += mins / 60;
	mins %= 60;
}

/*
Time Time::sum(Time& t) {
	Time sum;
	sum.mins = mins + t.mins;
	sum.hours = hours + t.hours;
	sum.hours += sum.mins / 60;
	sum.mins %= 60;
	return sum;
}
*/

Time Time::operator+(Time& t) {
	Time sum;
	sum.mins = mins + t.mins;
	sum.hours = hours + t.hours;
	sum.hours += sum.mins / 60;
	sum.mins %= 60;
	return sum;
}
void Time::show() {
	cout << "시간 : " << hours << endl;
	cout << "분 : " << mins << endl;

}

Time operator*(int n, Time& t) { // 구현할 떈 멤버 함수가 아니므로 Time:: 와 friend 키워드를 빼준다.
	/*Time result;
	long resultMin = t.hours * n * 60 + t.mins * n;
	result.hours = resultMin / 60;
	result.mins = resultMin % 60;*/
	return t * n;	  
}

Time Time::operator*(int n) {
	Time result;
	long resultMin = hours * n * 60 + mins * n;
	result.hours = resultMin / 60;
	result.mins = resultMin % 60;
	return result;
}

std::ostream& operator<<(std::ostream& os, Time& t) {
	os << t.hours << "시간" << t.mins << "분";
	return os;
 }


#pragma endregion

class NewTime : public Time {
private:
	int day;
public:
	NewTime();
	NewTime(int, int, int);
	//void print();
	void show();
};


NewTime::NewTime() : Time()/*C#의 base, Java의 super*/ {
	day = 0;

}

NewTime::NewTime(int h, int m, int d) : Time(h,m) {
	day = d;
}

//void NewTime::print() {
//	cout << "일 : " << day << endl;
//	show();
//}

void NewTime::show() {
	cout << "일 : " << day << endl;
	cout << "시간 : " << getHour() << endl;
	cout << "분 : " << getMins() << endl;
	
}
#pragma endregion







void main() {
#pragma region 추상화와 클래스
	//추상화와 클래스
	//클래스란?
	// 추상화를 사용자 정의 데이터형으로 변환해주는 수단
	// 추상화란?
	// 어떠한 객체를 사실적으로 표현하는 것이 아니라
	// 공통된 특징을 간결한 방식으로, 이해하기 쉽게 표현하는 것
	//  
	//
	{
		Stock temp = Stock("Panda", 100, 1000);

		temp.show();

		temp.buy(10, 1200);
		temp.show();
		temp.sell(5, 800);
		temp.show();

	}

#pragma endregion

#pragma region 생성자와 종료자
	{
		Stock temp = Stock("Panda", 100, 1000); // 생성자 사용 방법 1
		Stock temp2("Panda", 100, 1000); // 생성자 사용방법 2

		Stock temp3; // 디폴트 생성자를 이용해 객체 생성;

		temp3 = temp; // temp를 temp3에 대입

		temp.show(); // temp와 temp3출력
		temp3.show();

		temp = Stock("Coding", 200, 1000); // 생성자를 이용해 temp 내용 재설정;
		temp.show(); //재설정된 temp출력

	}

#pragma endregion

#pragma region this 포인터, 클래스 객체 배열
	{
Stock s1("A", 10, 1000);
	Stock s2("B", 20, 1200);

	cout << "\n\n";
	s1.show();
	s2.show();

	cout << "\n\n";


	cout << "A와 B중 share_val이 큰 객체는\n";
	s1.topval(s2).show();


	// 클래스 배열

	//Stock s[4]; // 아무것도 대입해주지않을 시 디폴트 생성자로 생성됨.
	Stock s[4] = { // 값 대입
		Stock("A",10,1000),
		Stock("B",30,1200),
		Stock("C",20,900),
		Stock("D",40,600),
	};

	s[0].show();


	Stock *first = &s[0]; // s[0]번째 stock을 직접 대입하는것이아닌 주소를 대입해줌
	for (int i = 1; i < 4; i++) {
		first = &first->topval(s[i]);
	}

	first->show();
	}
	
#pragma endregion

#pragma region 연산자 오버로딩
	 //연산자 오버로딩은 함수오버로딩 개념을 연산자로 가져온것
	 // 한 가지 연산자로 여러 역할을 하는 것
	 // ex) * : 주소에 적용될 시 주소에 있는 값을 산출하거나 값의 곱을 산출할 수 있음.
	 // 
	 // 연산자 오버로딩을 이용해 우리가만든 형식(클래스,...)을 연산을 할 수 있다.
	 // 선언 : 연산을 하는함수 이름을 "operator" + "하고자하는 연산기호"
	 // ex) void operator+
	 // 
	 //

	Time day1(1, 40);
	Time day2(2, 30);
	
	day1.show();
	cout << endl;
	day2.show();
	cout << endl;
	Time total;
	//total = day1.sum(day2); 
	total = day1.operator+(day2); // 사용법1
	total = day1 + day2; // 사용법2
	total.show();

	cout << endl;

#pragma endregion

#pragma region 프렌드
	
	//friend : public 이외에도 private로 접근 할 수 있는 통로.
	// 어떤 클래스의 이항 연산자를 오버로딩하면 friend를 쓸 필요가 생김.
	// 이항 연산자 : 두 개의 피연산자를 요구하는 연산자.
	// ex
	// Time 클래스의 operator*를 만드려고한다.
	//
	
	Time a, b;
	//a = b * 3; // 이것은 operator+처럼 Time과 Time이 연산하는 것이아닌 Time과 int의 연산 통해 Time클래스 값에 저장하는 방식
	//a = b.operator*(3);  // 위의 것을 풀어쓰면 이러한 식이 된다. 매개변수로 Time클래스가아닌 int형 변수이기 때문에 
						   //연산자 오버로딩으론 해결할 수 없는 문제가 생긴다. 그래서 프렌드를 쓰게된다.
	
	Time t1(1, 20);
	Time t2;

	t2 = 3 * t1;

	t2.show();

	// 이러면 문제점이생긴다. 3 * t1이아닌 t1 * 3으로 쓰게될 경우 매개변수의 위치가 달라 작동하지않는다.
	// freind키워드를 쓴 operator*를 오버로딩하는 방법도 있지만
	// freind키워드를 쓰지않고 operator(int)를 선언해주는 방법도있다.
	// 그후 freind키워드를 쓴 operator*의 내용을 return t * n으로 바꿔준다면 매개변수의 순서가 어찌되던 연산이된다.
	
	// 이렇게되면 friend operator*은 Time의 private 멤버변수에 접근하지 않기 때문에 friend키워드가 없어도 되지만
	// 써주는것이 바람직한 코딩 방법이다.
	// 클래스의 공식적인 함수중 하나이기 떄문이다.



#pragma endregion

#pragma region << 연산자 오버로딩
	{

	// 연산자 오버로딩과 friend를 사용해 <<연산자르 ㄹ오버로딩해보기
	Time t1(3, 45);
	// 본래 Time을 보려면 
	t1.show(); //를 써야하지만
	
	//cout << t1; // 이런식으로 쓸 수 있다면 코드가 더 직관적으로 들어올 것이다.

	int a = 5, b = 8;

	cout << a << b << endl; // 출력 값은 58
	//이것은
	(cout << a )<< b << endl; // cout 과 a 가 연산이 되고 그 결과 값이 다시 b와 연산되는 과정이라고 볼수 있다.
 	
	cout << t1 << endl; // 이를 풀어보면
	operator<<(cout,t1) << endl; // 이런식이 된다.

	cout << "\n";
	}

#pragma endregion

#pragma region 상속
	{
		/*
		1. 기존의 클래스에 새로운 기능을 추가할 수 있다.
		2. 클래스가 나타내고 있는 데이터에 다른 것을 더 추가할 수 있다.
		3. 클래스 메서드가 동작하는 방식을 변경할 수 있다.
		방법 : class Name : public ParentClassName

		1. 파생 클래스형의 객체 안에는 기초 클래스형의 데이터 멤버들이 저장된다.
		2. 파생 클래스형으ㅣ 객체는 기초 클래스형으 ㅣ메서드들을 사용할 수 있다.
		3. 파생 클래스는 자기 자신으ㅣ생성자를 필요로한다.
		4. 파생 클래스는 부가적인 데이터 멤버들과 멤버 함수들을 임의로 추가할 수 있다.
		
		파생클래스는 부모클래스의 private 멤버를 접근할 수 없다.
		*/
		{

		NewTime temp1();
		NewTime temp2(3,30,2);

		}

		//temp2.print();

		// virtual 키워드 : 메서드가 재정의될 수 있도록 붙이는 키워드
	
		Time temp1(30, 2);
		NewTime temp2(3, 30, 2);

		temp1.show(); // 시 분 2개만 나옴
		cout << endl;
		temp2.show(); // 일 시 분 3개가 나옴

		/*
		1. 기초 클래스에서 가상메서드를 선언하면,
		그 함수는 기초 클래스 및 파생되는 클래스에서 모두 가상이 된다.
		2. 객체에 대한 참조를 사용하여, 객체를 지시하는 포인터를 사용하여
		가상 메서드가 호출되면 참조나 포인터를 위해 정의된 메서드를  사용하지않고
		객체형을 위해 정의된 메서드를 사용한다. > 동적 결합
		3. 상속을 위해 기초 클래스로 사용할 클래스를 정의할 때,
		파생 클래스에서 다시 정의해야 되는 클래스 메서드들은 가상 함수로 선언해야 한다.
		*/
	


		// C++또한 업캐스팅을 할 수 있다.

	}
#pragma endregion


}

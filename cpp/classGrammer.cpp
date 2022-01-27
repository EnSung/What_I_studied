#include <iostream> //전처리 지시자
#include <climits>
#include <cstring>
#include <string>



#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// 원래는 따로 cpp 파일을 만들어 함수 구현부를 따로 빼주는것이 편함

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

void Stock::buy(int n , float pr) {// Stock클래스의 사용범위에 결정된다로 받아드려짐.
	shares += n;
	share_val = pr ;
	set_total();

}
void Stock::sell(int n , float pr) {
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

#pragma endregion

}

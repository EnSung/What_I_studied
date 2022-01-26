#include <iostream> //전처리 지시자
#include <climits>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS
using namespace std; 


int sumArray(int*, int);
int sumArray2(int*, int*);
int main() {

#pragma region 기본적인 자료형과 형변환
	{
	cout << "Hello, World!" << endl;

	// ''가 아닌 ""는 명시적으로 NULL 문자가 있음 ( NULL문자를 보면 컴파일러가 출력을 끝냄)
	// 그래서 char a = "C"가 안됨 => NULL이 포함되어 char형에 모두 안들어감

	int a = 77;
	//형 변환
	//typeName(a) , (typeName)a
	// 이것은 우리가 잘 알고 있던 C 에서도 쓰는 문법

	//하지만 C++에선?
	//static_cast<typeName>(a)
	// 둘다 사용가능하지만 차이점은 나중에

	cout << static_cast<char>(a) << endl;
}
#pragma endregion

#pragma region 산술과 AUTO
	// 연산자 동일 + - * / %
	// % = 소수에서 사용불가
	// 
	//auto 형 자료형
	// C#의 var형식같은 자료형 초기호ㅘ를 해줄 떄 값을 주면 자동으로 자료형이 적용됨
	{
	auto n = 100; // int
	auto x = 1.5; // float
	auto y = 1.3e12L; // long long
	}
#pragma endregion

#pragma region 배열과 문자열

	//선언 typeName arrayName[arraySize];

	// C와 동일하게 설명함
#pragma endregion

#pragma region 입력 및 string
	{
	//strlen => 문자열 길이 구함 (sctring헤더 필요)

	//입력 cin
	//char name1[255];
	//cin >> name1; // 하지만 이것은 공백이 나오면 끊어버리기에 이름에  정 은성 이라고 칠 수 없다   (저렇게 입력 시 "정" 한 문자만 나옴)

	//cin.getline(변수, 크기);
	// 공백을 포함 해 한 줄을 입력받음

	//cin.getline(name1, 255);




	//string
	/*
	* C스타일로 string 객체를 초기화할 수 있다. => 선언ㅊ ㅗ기화 등등
	* cin을 사용해 string 객체에 키보드 입ㄹㄱ을 저장할 수 있다.
	* cout을 사용해 string 객체를 출력 가능
	* 배열 표기를 사용해 string 객체에 저장되어 있는 개별적인ㅇ 문자들에 접근할 수 있다.

	string == 문자열

	차이 : 배열은 다른 배열에 통째로 대입할 수 없다. 하지만 string에선 가능
	*/

	char name1[15];
	char name2[15] = "Naming";

	//name1 = name2; => X

	string namee1;
	string namee2 = "Naming";

	namee1 = namee2;// => O

	cout << namee1 << endl;

	cout << namee1[2] << endl; // 배열처럼 인덱스로 참조 가능

}



#pragma endregion

#pragma region 구조체
	{
	//배열 같은 경우 : 같은ㅇ 데이터형의 집합 (같은 데이터형이어야함)
	//구조체 같은 경우 : 데이터의 집합 ( 다른 데이터형이 허용됨)

	//ex)축구선수

	/*string name;
	string position;
	float height;
	float weight;
	string teamName;*/

	//등등...
	// 너무 많음. 하지만 이건 단 한명의 데이터라는것, 또한 모두 다른 자료형이라 배ㅐ열로 저장도 할 수 없음.

	// 구조체 선언
	struct MyStruct
	{
		//멤버라고 불리는 구성요소들 (변수들)
		string name;
		string position;
		int height;
		int weight;
		string teamName;
	} B;
	// 뒤에 B를 붙여놈으로써 선언과 함께 MyStruct형의 선언된 값으로 B라는 변수를 만들 수 있음
	// 값이 없을 시 0

	// 또한 구조체를 변수처럼 쓰 ㄹ 수 있음
	MyStruct A;
	//값 대입
	A.name = "Son";
	A.position = "Striker";
	A.height = 183;
	A.weight = 77;

	// 초기화 방법
	MyStruct AA = {
		"Sun",
		"Striker",
		185,
		66
	};

	//구조체도 배열로 선언 가능
}
#pragma endregion
	
#pragma region 공용체와 열거체

	// 공용체(union)
	// 서로 다른 데이터형을 한 번에 한 가지만 보관할 수 있음.
	//
	{
		// ex
		union MyUnion
		{
			int intVal;
			long longVal;
			float floatVal;
		};

		MyUnion test;

		// 이럼 구조체와 다른게 뭐지?

		test.intVal = 3;
		cout << test.intVal << endl;
		test.longVal = 33;
		cout << test.intVal << endl;
		cout << test.longVal << endl;
		test.floatVal = 3.3;
		cout << test.intVal << endl;
		cout << test.longVal << endl;
		cout << test.floatVal << endl;

		// Union은 한번에 한번의 데이터만 보관
		// intVal을 보관하다 다른 값이 들어오면 이전 데이터는 소실된다.
		// 구조체 처럼 여러가지 데이터형을 사용할 수 있지만 이들을 동시에 사용할 순 없다.



		//열거체(enum)
		//기호 상수를 만드는 것에 대한 또 다른 방법.

		enum spectrum { red = 0, orange = 4, yellow, green, blue, violet, indigo, ultraviolet };
		// 열거자들의 값을 지정해 줄 수 있음 ( 꼭 정수로 해아함 )
		// 또한 값이 지정되지않은 열거자들을 이전 열거자 + 1 의 값을 가지게 됨
		/*
			사용법
			1. spectrum을 새로운 데이터형 이름으로 만든다.
			2. red, orange, yellow 등등.. 을 0~ 7까지 정수 값을 각각 나타내는 기호 상수로 만듦.
		*/


		spectrum color1 = orange;

		int a = color1;
		cout << a << endl; // 1이 출력됨
		//spectrum color1 = orange + yellow; 열거자 끼리 연산은 X 

		int b = blue;
		b = blue + 3; // blue는 열거체 안에서 4, 7이라는 값이 대입됨 

	}
#pragma endregion

#pragma region 포인터
	{
		// 변수를 만들 때 우리 눈에 보이지않지만 주솟값을 가지고있음, 그것을 가지고 변수를 추적함.

		int val = 3;

		// & : 주소연산자
		cout << &val << endl;

		//C++ : 객체지향 프로그래밍
		//객체지향 프로그래밍의 특징 : 컴파일 시간이 아닌 실행 시간에 어ㄸㅓ한 결정을 내릴 수 있다, 융통성을 가지고 있음.

		//포인터 : 사용할 주소에 이름을 붙인다.
		//즉, 포인터는 포인터의 이름이 주소를 나타냅니다.
		//   * : 간접값 연산자, 간접 참조 연산자 

		{
			int* a; //C style
			int* b; // C++ style
			int* c, d; //c는 포인터 변수, d는 int형 변수
		}

		int a = 6;
		int* b;
		b = &a; // b의 주소를 a의 주솟값으로 바꿈. 그럼 a,b모두 같은 주소값을 가리키게됨.

		cout << endl;
		cout << endl;
		cout << endl;

		cout << "a의 값 " << a << endl;
		cout << "*b의 값 " << *b << endl;
		cout << "a의 주소 " << &a << endl;
		cout << "b*의 주소" << b << endl;


		*b += 1; // b위치에있는 값에 1을 더 함. << a도 같은 위치를 가르키므로 a의 값도 1이 증가됨 

		cout << "이제 a의 값은 " << a << endl;

		// 이름이 없는 메모리, 즉 아직 결정되지 않은 메모리를 대입할 수 있다. 그것이 포인터의 핵심.


		//new 연산자
		/*
		어떤 데이터 형을 원하는지 new 연산자에게 알려주면,
		new 연ㅅ간자는 그에 맞는 크기의 메모리 블록을 찾아내고 그 블록의 주소를 리턴한다.
		*/

		int* pointer = new int; // new 연산자 사용

// 그럼 이것과 다른 점이 무엇일ㅇ까?
int aa;
int* bb = &aa;

// new 연산자를 사용한 경우 생성된 것은 pointer로 밖에 접근할 수 없다.
// 하지만 위와같은 방법은 aa라는 변수 명으로도 접근이 가능함.



// delete 연산자

/*
사용한 메모리를 다시 메모리 폴로 환수
환수된 메모리는 프로그램의 다른 부분에서 다시 사용
*/

/*
1. new로 대입하지 않는 메모리는 delete로 해제할수 없다.
2. 같은 메모리 블록을 연달아 두 번 delete 로 해제할 수 없다.
3. new[]로 메모리를 대입할 경우 delete[]로 해제한다.(배열)
=> 대괄호를 사용하지 않았다면 delete도 대괄호를 사용하지 않아야 한다.
*/

int* ps = new int; // 메모리 사용
delete ps; // 메모리 다시 반환
//반환하지 않으면 대입은 됐지만 나중에 사용하지않아 메모리 누수가 되고 계속 메모리 누수가 되게되면 프로그램은 먹통된다.

// ex

double* p3 = new double[3];
p3[0] = 0.2;
p3[1] = 0.5;
p3[2] = 0.8;

cout << "p3[1] is " << p3[1] << endl;

p3 = p3 + 1;  // 포인터를 증가시킨다.

cout << "Noew p3[0] is " << p3[0] << " and ";
cout << "p3[1] is " << p3[1] << endl;

p3 = p3 - 1; // 다시 시작 위치를 지시한다.
delete[] p3; // 배열 메모리 해제



char animal[20];
char* p2;

cout << "\n\n\n";
cout << "동물 이름을 입력하십시오\n";
cin >> animal;

p2 = new char[strlen(animal) + 1]; // 실행중 배열의 크기를 정하는 것
strcpy(p2, animal);

cout << "입력하신 동물 이름을 복사하였습니다" << endl;
cout << "입력하신 동물 이름은 " << animal << "이고, 그 주소는 " << (int*)animal << "입니다." << endl;
cout << "복사된 동물 이름은 " << p2 << "이고, 그 주소는 " << (int*)p2 << "입니다." << endl;


// 동적 구조체 생성

// 동적으로 생성된 구조체는 참졸르하기위해 . 이아닌 -> 를 쓴다.
// 이것이 싫다면 (*구조체변수이름). 으로 참조 가능
struct MyStruc {
	char name[20];
	int age;
};

MyStruc* temp = new MyStruc; // 동적 구조체 생성

cout << "\n\n\n";

cout << "당신의 이름을 입력하십시오";
cin >> temp->name;

cout << "당신의 나이를 입력하십시오";
cin >> temp->age;

cout << "안녕하세요! " << temp->name << "씨!" << endl;
cout << "당신은 " << temp->age << "살 이군요!" << endl;
		}
#pragma endregion

#pragma region 반복문, 조건문

		// 반복문과 조건문은 C의 문법과 똑같다.
#pragma endregion

#pragma region 함수

		// 함수의 형태 
		// C문법과 동일

		// 함수와 배열

		// 배열이름을 배열의 첫번째 인덱스 주소로 인식
		// 즉arr == &arr[0]

		// 따라서 배열을 포인터 매개변수로 받을 수 있다.

	{
	//ex

		int tempArray[20] = {
			1,2,3,4,5,6,7,8,9,10,23,4,5,33,5,3,5,3
		};

		cout << sizeof tempArray << endl; // 80 출력 => 배열의 전체 크기



		cout << sumArray(tempArray, 20) << endl;

		int tempArray2[20] = {
			1,2,3,4,5,6,7,8,9,10,23,4,5,33,5,3,5,3
		};

		cout << "함수의 열 번째 인덱스까지의 합은 " << sumArray2(tempArray2, tempArray2 + 10) << "입니다.\n";
	}
		
#pragma endregion

	return 0;
}	



int sumArray(int* arrays, int arraySize) {

	cout << sizeof arrays << endl; // 8 출력 => 배열의 주솟값 크기

	int total = 0;

	for (int i = 0; i < arraySize; i++)
	{
		total += arrays[i];
	}

	return total;
}

int sumArray2(int* beginIndex, int* endIndex) {


	int total = 0;
	
	for (int* i = beginIndex; i != endIndex; i++)
	{
		total += *i;
	}

	return total;
}

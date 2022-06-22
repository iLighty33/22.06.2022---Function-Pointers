#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>

void F00()
{

}

void F03()
{

}

struct Coord {
	int X;
	int Y;
	bool operator<(Coord& other)
	{
		return true;
	}
};

bool F01(Coord& a, Coord& b)
{
	return a.X < b.X;
}

class Functor {
public:
	bool operator()(Coord& a, Coord& b)
	{
		return a.X < b.X;
	}
	template<typename T, typename... Args> // Вариативный шаблон.

	T operator()(Args... args)
	{
		return T();
	}
};

class Fish {
public:
	Fish() {};
	Fish(std::string name, int age, int size)
	{
		name_ = name;
		age_ = age;
		size_ = size;
	}
	~Fish() {};

	
	friend std::ostream& operator << (std::ostream& out, const Fish& obj)
	{
		out << "Name: " << obj.name_ << " ";
		out << "Age: " << obj.age_ << " ";
		out << "Size: " << obj.size_ << "\n";
		return out;
	}

		bool operator<(Fish& other)
	{
		return true;
	}
		std::string name_;
		int age_;
		int size_;
private:


};


bool lessAge(const Fish& a, const Fish& b)
{
	return a.age_ < b.age_;
}


int main()
{

	std::vector<Fish> coll2{ {"Zolotaya", 2, 5}, {"Serebryannaya", 3, 6,}, {"Bronzovaya", 1, 6} };
	for (const auto& fish : coll2)
	{
		std::cout << fish;
	}

	std::sort(
		coll2.begin(), coll2.end(), lessAge);
	for (const auto& fish : coll2)
	{
		std::cout << fish;
	}

	[/*захват контекста*/](/*аргументы*/) {/*тело функции*/};

	auto lam =
		[](const Fish& a, const Fish& b)->bool {
		if (true)
		{
			return a.size_ < b.size_;
		}
		else
		{
			return "";
		}
	};
		//return a.size_ < b.size_; };

	return 0;
}
/*	bool(*p)(int age, int size);
	std::function<void(void)> funktor2 = F03;
	Functor funct2;
	std::sort(coll2.begin(), coll2.end());
	*/
	/*
	std::vector<Coord> coll{{1,2}, {3,1}, {1,32}, {6,8}};
	std::vector<int> numbers{ 4, 5, 6, 32, 3, 5, 6, 7, 11, 56 };
	bool(*p)(Coord&, Coord&) = F01;
	void(*p)(void) = F00;
	std::function<void(void)> funktor = F00;
	Functor funct;
	std::sort(numbers.begin(), numbers.end());
	std::sort(coll.begin(), coll.end(), F01);*/

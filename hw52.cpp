#include <iostream>
#include <string>

class Figuries
{
public:
	int sides_count;
	std::string Figure_Name;

	Figuries()
	{
		sides_count = 0;
		Figure_Name = "Фигура";
	}
	Figuries(int sides_count_FC, std::string Figure_Name_FC) : sides_count(sides_count_FC), Figure_Name(Figure_Name_FC) {}

	int get_sides_count()
	{
		return sides_count;
	}
	std::string get_figura_name()
	{
		return Figure_Name;
	}

	virtual void print_sides_dim()
	{
		std::cout << "no sides" << std::endl;
	}

	virtual void print_engels_dim()
	{
		std::cout << "no engels" << std::endl;
	}
};

class Triangele : public Figuries
{
public:
	// a,b,c - стороны/ A,B,C - углы
	int aT, bT, cT, AT, BT, CT;
	Triangele(int sides_count_T = 3, std::string Figura_Name_T = "Треугольник") : Figuries(sides_count_T, Figura_Name_T), aT(10), bT(20), cT(30), AT(50), BT(60), CT(70) {}

	int get_CT()
	{
		return CT;
	}

	void print_sides_dim() override
	{
		std::cout << "Стороны: a = " << aT << " b = " << bT << " c = " << cT << std::endl;
	}

	void print_engels_dim() override
	{
		std::cout << "Углы: А = " << AT << " В = " << BT << " С = " << CT << std::endl;
	}
};

class Right_Triangele : public Triangele
{
public:
	int CRT;
	Right_Triangele(int sides_count_RT = 3, std::string Figura_Name_RT = "Прямоугольный треугольник") : Triangele(sides_count_RT, Figura_Name_RT), CRT(90) {}

	void print_sides_dim() override
	{
		std::cout << "Стороны: a = " << aT << " b = " << bT << " c = " << cT << std::endl;
	}

	void print_engels_dim() override
	{
		std::cout << "Углы: А = " << AT << " В = " << BT << " С = " << CRT << std::endl;
	}
};


class Isosceles_Triangele : public Triangele
{
public:
	int aIT, cIT;
	Isosceles_Triangele(int sides_count_IT = 3, std::string Figura_Name_IT = "Равнобедренный треугольник") : Triangele(sides_count_IT, Figura_Name_IT), aIT(10), cIT(10) {}

	void print_sides_dim() override
	{
		std::cout << "Стороны: a = " << aIT << " b = " << bT << " c = " << cIT << std::endl;
	}

	void print_engels_dim() override
	{
		std::cout << "Углы: А = " << AT << " В = " << BT << " С = " << CT << std::endl;
	}

};

class Equilateral_Triangele : public Triangele
{
public:
	int aET, bET, cET, AET, BET, CET;
	Equilateral_Triangele(int sides_count_ET = 3, std::string Figura_Name_ET = "Равносторонний треугольник") : Triangele(sides_count_ET, Figura_Name_ET), aET(10), AET(60) {
		bET = cET = aET;
		BET = CET = AET;
	}

	void print_sides_dim() override
	{
		std::cout << "Стороны: a = " << aET << " b = " << bET << " c = " << cET << std::endl;
	}

	void print_engels_dim() override
	{
		std::cout << "Углы: А = " << AET << " В = " << BET << " С = " << CET << std::endl;
	}
};

class Quadrangle : public Figuries
{
public:
	int aQ, bQ, cQ, dQ, AQ, BQ, CQ, DQ;
	Quadrangle(int sides_count_Q = 4, std::string Figura_Name_Q = "Четырёхугольник") : Figuries(sides_count_Q, Figura_Name_Q), aQ(10), bQ(20), cQ(30), dQ(40), AQ(50), BQ(60), CQ(70), DQ(80) {}

	void print_sides_dim() override
	{
		std::cout << "Стороны: a = " << aQ << " b = " << bQ << " c = " << cQ << " d = " << dQ << std::endl;
	}

	void print_engels_dim() override
	{
		std::cout << "Углы: А = " << AQ << " В = " << BQ << " С = " << CQ << " D = " << DQ << std::endl;
	}
};

class Rectangle : public Quadrangle
{
public:
	int aR, bR, cR, dR, AR, BR, CR, DR;
	Rectangle(int sides_count_R = 4, std::string Figura_Name_R = "Прямоугольник") : Quadrangle(sides_count_R, Figura_Name_R), aR(10), bR(20), AR(90) {
		cR = aR;
		dR = bR;
		BR = CR = DR = AR;
	}

	void print_sides_dim() override
	{
		std::cout << "Стороны: a = " << aR << " b = " << bR << " c = " << cR << " d = " << dR << std::endl;
	}

	void print_engels_dim() override
	{
		std::cout << "Углы: А = " << AR << " В = " << BR << " С = " << CR << " D = " << DR << std::endl;
	}
};

class Square : public Quadrangle
{
public:
	int aS, bS, cS, dS, AS, BS, CS, DS;
	Square(int sides_count_S = 4, std::string Figura_Name_S = "Квадрат") : Quadrangle(sides_count_S, Figura_Name_S), aS(20), AS(90) {
		dS = bS = cS = aS;
		BS = CS = DS = AS;
	}

	void print_sides_dim() override
	{
		std::cout << "Стороны: a = " << aS << " b = " << bS << " c = " << cS << " d = " << dS << std::endl;
	}

	void print_engels_dim() override
	{
		std::cout << "Углы: А = " << AS << " В = " << BS << " С = " << CS << " D = " << DS << std::endl;
	}
};

class Parallelogram : public Quadrangle
{
public:
	int aP, bP, cP, dP, AP, BP, CP, DP;
	Parallelogram(int sides_count_P = 4, std::string Figura_Name_P = "Параллелограмм") : Quadrangle(sides_count_P, Figura_Name_P), aP(20), bP(30), AP(30), BP(40) {
		cP = aP;
		dP = bP;
		CP = AP;
		DP = BP;
	}

	void print_sides_dim() override
	{
		std::cout << "Стороны: a = " << aP << " b = " << bP << " c = " << cP << " d = " << dP << std::endl;
	}

	void print_engels_dim() override
	{
		std::cout << "Углы: А = " << AP << " В = " << BP << " С = " << CP << " D = " << DP << std::endl;
	}
};

class Rhombus : public Quadrangle
{
public:
	int aRS, bRS, cRS, dRS, ARS, BRS, CRS, DRS;
	Rhombus(int sides_count_RS = 4, std::string Figura_Name_RS = "Параллелограмм") : Quadrangle(sides_count_RS, Figura_Name_RS), aRS(20), ARS(30), BRS(40) {
		dRS = bRS = cRS = aRS;
		CRS = ARS;
		DRS = BRS;
	}

	void print_sides_dim() override
	{
		std::cout << "Стороны: a = " << aRS << " b = " << bRS << " c = " << cRS << " d = " << dRS << std::endl;
	}

	void print_engels_dim() override
	{
		std::cout << "Углы: А = " << ARS << " В = " << BRS << " С = " << CRS << " D = " << DRS << std::endl;
	}
};

void print_info(Figuries* input_figures)
{
	std::cout << input_figures->get_figura_name() << std::endl;
	input_figures->print_sides_dim();
	input_figures->print_engels_dim();
	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian"); // задать русский текст
	std::system("chcp 1251"); // настроить кодировку консоли
	std::system("cls"); // очистить экран

	Figuries* Custom_Figure[9];
	Custom_Figure[0] = new Triangele{};
	Custom_Figure[1] = new Right_Triangele{};
	Custom_Figure[2] = new Isosceles_Triangele{};
	Custom_Figure[3] = new Equilateral_Triangele{};
	Custom_Figure[4] = new Quadrangle{};
	Custom_Figure[5] = new Rectangle{};
	Custom_Figure[6] = new Square{};
	Custom_Figure[7] = new Parallelogram{};
	Custom_Figure[8] = new Rhombus{};

	for (int i = 0; i < 9; i++)
	{
		print_info(Custom_Figure[i]);
	}

	for (int i = 0; i < 9; i++)
	{
		delete Custom_Figure[i];
	}
	return 52;
}
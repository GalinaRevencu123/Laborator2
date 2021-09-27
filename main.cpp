#include <iostream>
#include <queue>
#include <cstdlib>
#include<conio.h>
#include<stdlib.h>
using namespace std;

#define M 10

class Box
{
public:
	int height;
	int	width;
	int depth;
public:
	Box()
	{
		height = 0;
		width = 0;
		depth = 0;
	}
public:
	Box(int h, int w, int d)
	{
		height = h;
		width = w;
		depth = d;
	}
public: void
	Read(){
		cout << "\n\t---Introduceti datele---" << endl;
		cout << "\tInaltimea:";	cin >> height;
		cout << "\tLatimea:" ;cin >> width;
		cout << "\tAdincimea:" ;cin >> depth;
	}
public: void
	Display() {
		cout << "\n\t---Afisarea datele---" << endl;
		cout << "\tInaltimea:" << height <<endl;
		cout << "\tLatimea:" << width << endl;
		cout << "\tAdincimea:" << depth << endl;
	}
public: int Volum_Box() {
	return height * width * depth;
}
public: int Aria_Box() {
	return 2*(height*width + height*depth+width*depth);
}
};


class  Queue
{
public:
	int tab[M];
	int nr_elem_Max;
	int prim_Elem;
	int ult_Elem;
	int k;

int Marime() {
		return k;
	}
bool Full() {
		return (Marime() == nr_elem_Max);
	}
public:
	Queue() {
		prim_Elem = 0;
		ult_Elem = 0;
	}
public:
	Queue( int prim, int u) {
		prim_Elem = prim;
		ult_Elem = u;
	}

public:	void
	Push_Queue() {
		if (ult_Elem == M)
			cout << "\n\tNumarul maxim a fost atins!";
		else {
			cout << "\n\tIntroduceti vaoloarea : ";
			cin >> nr_elem_Max;
			cout << "\n\tPozitia : " << ult_Elem + 1 << " , Valoarea  : " << nr_elem_Max;
			tab[ult_Elem++] = nr_elem_Max;
		}
}

public:	 void
	Display() {
		  cout << "\n\tMarimea : " << (ult_Elem -prim_Elem);
		  for (int i = nr_elem_Max; i < ult_Elem; i++)
			  cout << "\n--Elementul : " << i << " , Valoare  : " << tab[i];
	  }
public:	 void
	 PoP_Queue() {
	if (prim_Elem == ult_Elem)
		cout << "\n\tCoada este fara elemente!";
	else {
		cout << "\n\tPozitia : " << prim_Elem + 1 << " , Valoarea inlaturata  :" << tab[prim_Elem];
		prim_Elem++;
	}
}
};

int main() {
	queue <int> q;
	Queue Q;
	Box b;
	int n;//numarul de cutii
	int m;//numarul de elemente in coada
	cout << "\n\t----Problema Boxe----";
	cout << "\n\tIntroduceti numarul de elemente:";
	cin >> n;// numarul de elemete
	for (int i = 0; i < n; i++)//ciclu de citire/afisare a nr elemente de le tasta
	{
		b.Read();
		b.Display();
		cout << "\n\tVolumul cutiei: "<<b.Volum_Box();
		cout << "\n\tAria cutiei: " << b.Aria_Box()<<endl;
	}
	//Coada utilizind biblioteca
	cout << "\n\t---------------------------------------------";
	cout << "\n\t----Problema Coada Default Bibioteca----";
	cout << "\n\n\t---Afisarea cozii---"<<endl;
	cout << "\n\tIntroduceti numarul de elemente:";
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cout << "\tElemetele:"<<i<<endl;
		q.push(i);//adaugarea elem
	}
	cout << "\n\tMarimea cozii:" << q.size() << endl;
	cout << "\n\tPrimul element: " << q.front() << endl;
	cout << "\n\tUltimul element: " << q.back() << endl;
	q.pop(); //eliminarea
	cout << "\n\tMarimea cozii finale:" << q.size() << endl;
	cout << "\n\t---------------------------------------------";
	cout << "\n\t----Problema Coada prin Clasa----";
	//Coada prin clasa // cel mai bine era de facut un meniu ,dar cine sa-l faca la 22:30 xD 🙂
	Q.Push_Queue();
	Q.Display();
	Q.PoP_Queue();
}

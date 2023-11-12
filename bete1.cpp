#include <fstream>
#include <algorithm>
#define NMAX 1000
using namespace std;
int n, a[NMAX], b[NMAX];
void citesteDateleDeIntrare();
void afiseazaRezultat();
int main()
{
	citesteDateleDeIntrare();
	afiseazaRezultat();
	return 0;
}
int maxim(int v[], int n)
{
	// returneaza valoarea maxima din vectorul v cu n elemente
	int max = v[0];
	for (int i = 1; i < n; i++)
		if (v[i] > max)
			max = v[i];
	return max;
}
int minim(int v[], int n)
{
	// returneaza valoarea minima din vectorul v cu n elemente
	int min = v[0];
	for (int i = 1; i < n; i++)
		if (v[i] < min)
			min = v[i];
	return min;
}
int primaPozitie(int x, int v[], int n)
{
	// returneaza prima pozitie a lui x
	// in vectorul sortat crescator v cu n elemente
	// daca x se afla in vector, sau -1 altfel
	int st = -1, dr = n;
	while (dr-st > 1)
	{
		int mij = st + (dr-st)/2;
		if (v[mij] < x)
			st = mij;
		else
			dr = mij;
	}
	if (dr == n || v[dr] != x)
		return -1;
	return dr;
}
int nrBeteLungime(int lg)
{
	sort(a, a+n);
	sort(b, b+n);
	int uz[NMAX], i, nr=0, poz, dif;
	for (i = 0; i < n; i++)
		uz[i] = 0;
	for (i = 0; i < n; i++)
	{
		dif = lg-a[i];
		poz = primaPozitie(dif, b, n);
		if (poz >= 0)
		{	
			for (; uz[poz] && b[poz] == dif && poz < n; poz++);
			if (poz < n)
				if (b[poz] == dif)
					nr++, uz[poz] = 1;
		}
	}
	return nr;
}
int lungimeCelMaiLungBat()
{
	return maxim(a, n) + maxim(b, n);
}
int lungimeInitialaBete()
{
	return minim(a, n) + maxim(b, n);
}
void afiseazaRezultat()
{
	ofstream fout("bete1.out");
	fout << lungimeInitialaBete() << '\n';
	int lgmax = lungimeCelMaiLungBat();
	fout << lgmax << '\n' << nrBeteLungime(lgmax);
	fout.close();
}
void citesteDateleDeIntrare()
{
	ifstream fin("bete1.in");
	fin >> n;
	int i;
	for (i = 0; i < n; i++)
		fin >> a[i];
	for (i = 0; i < n; i++)
		fin >> b[i];
	fin.close();
}

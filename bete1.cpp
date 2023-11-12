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
bool exista(int x, int v[], int n)
{
	// verifica daca x se afla in vectorul v cu n elemente
	int st = 0, dr = n;
	while (dr - st > 1)
	{
		int mij = st + (dr - st)/2;
		if (v[mij] == x)
			return 1;
		if (v[mij] < x)
			st = mij;
		else
			dr = mij;
	}
	return 0;
}
int nrBeteLungime(int lg)
{
	sort(a, a+n);
	sort(b, b+n);
	int nr = 0;
	for (int i = 0; i < n; i++)
	{
		int dif = lg - a[i];
		if (exista(dif, b, n))
			nr++;
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

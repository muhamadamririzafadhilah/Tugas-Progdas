#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int CLASS_SIZE = 20;
const int NAME_COL = 22; // lebar kolom nama agar rata kiri rapi

struct studentType
{
    string studentFName; // nama depan (satu kata)
    string studentLName; // nama belakang (satu kata)
    int testScore;       // untuk nilai dari 1 sampai 100
    char grade;          // menentukan nilai A/B/C/D/F(fail)
};

// Prototipe fungsi
void readStudents(istream &in, studentType a[], int n);
char scoreToGrade(int s);
void assignGrades(studentType a[], int n);
int findHighestScore(const studentType a[], int n);
void printAll(const studentType a[], int n, ostream &out);
void printTopStudents(const studentType a[], int n, int highest, ostream &out);

int main()
{
    studentType cls[CLASS_SIZE];

    readStudents(cin, cls, CLASS_SIZE);
    assignGrades(cls, CLASS_SIZE);

    int highest = findHighestScore(cls, CLASS_SIZE);

    printAll(cls, CLASS_SIZE, cout);
    printTopStudents(cls, CLASS_SIZE, highest, cout);

    return 0;
}
// Baca n siswa: "FirstName LastName Score"
void readStudents(istream &in, studentType a[], int n)
{
    cout << "Masukkan data " << n << " siswa (FirstName LastName Score 0..100)\n";
    for (int i = 0; i < n; ++i)
    {
        int sc;
        in >> a[i].studentFName >> a[i].studentLName >> sc;

        // membatasi rentang ke 0 sampai 100
        if (!in)
        { // jika input tidak valid
            cerr << "Input tidak valid pada baris ke-" << (i + 1) << ". Mengisi default.\n";
            a[i].studentFName = "Unknown";
            a[i].studentLName = "Unknown";
            sc = 0;
            in.clear();
        }
        if (sc < 0)
            sc = 0;
        if (sc > 100)
            sc = 100;

        a[i].testScore = sc;
        a[i].grade = ' ';
    }
}

// Pemetaan skor ke grade A/B/C/D/F
char scoreToGrade(int s)
{
    if (s >= 90)
        return 'A';
    if (s >= 80)
        return 'B';
    if (s >= 70)
        return 'C';
    if (s >= 60)
        return 'D';
    return 'F';
}

// mengisi grade semua siswa
void assignGrades(studentType a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        a[i].grade = scoreToGrade(a[i].testScore);
    }
}

// Skor tertinggi
int findHighestScore(const studentType a[], int n)
{
    int hi = a[0].testScore;
    for (int i = 1; i < n; ++i)
    {
        if (a[i].testScore > hi)
            hi = a[i].testScore;
    }
    return hi;
}

// Cetak tabel nilai: "Last, First" (left-justified), lalu skor & grade
void printAll(const studentType a[], int n, ostream &out)
{
    out << "\nDaftar Nilai Siswa\n";
    out << left << setw(NAME_COL) << "Nama (Last, First)"
        << right << setw(8) << "Skor"
        << setw(8) << "Grade" << '\n';
    for (int i = 0; i < n; ++i)
    {
        string formattedName = a[i].studentLName + ", " + a[i].studentFName;
        out << left << setw(NAME_COL) << formattedName
            << right << setw(8) << a[i].testScore
            << setw(8) << a[i].grade << '\n';
    }
}

// Cetak semua siswa yang meraih nilai tertinggi
void printTopStudents(const studentType a[], int n, int highest, ostream &out)
{
    out << "\nHighest Test Score: " << highest << '\n';
    out << "Students with the highest score:\n";
    for (int i = 0; i < n; ++i)
    {
        if (a[i].testScore == highest)
        {
            out << a[i].studentLName << ", " << a[i].studentFName << '\n';
        }
    }
}


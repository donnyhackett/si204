#include <iostream>
#include <fstream>
using namespace std;

int** readPGM(string, int, int, istream&);
void writePGM(string, int**, int, int);
void posterize(string, int**, int, int);
void mirror(string, int**, int, int);
void merge(string, int**, int**, int, int);
void rotate(string, int**, int, int);

int main()
{
    cout << "filename: ";
    string file1;
    cin >> file1;


    cout << "output filename: ";
    string outfile;
    cin >> outfile;

    ifstream fin1(file1);
    string temp;
    int width1, height1;
    fin1 >> temp >> width1 >> height1 >> temp;
    int** pic1 = readPGM(file1, width1, height1, fin1);

    
    

    rotate(outfile, pic1, width1, height1);
    
    return 0;
}

int** readPGM(string file, int width, int height, istream& fin)
{
    
    int** pic = new int*[height];
    for(int i = 0; i < height; i++)
    {
        pic[i] = new int[width];
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            fin >> pic[i][j];
        }
    }
    return pic;
}

void writePGM(string file, int** pic, int width, int height)
{
    ofstream fout(file);
    fout << "P2" << endl;
    fout << width << " " << height << endl;
    fout << "255" << endl;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(j == width - 1)
            {
                fout << pic[i][j];
            }
            else
                fout << pic[i][j] << " ";
        }
        fout << endl;
    }
}

void posterize(string file, int** pic, int width, int height)
{
    ofstream fout(file);
    fout << "P2" << endl;
    fout << width << " " << height << endl;
    fout << "255" << endl;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(j == width - 1)
            {
                if(pic[i][j] > 128)
                    fout << 255;
                else
                    fout << 0;
            }
            else
                if(pic[i][j] > 128)
                    fout << 255 << " ";
                else
                    fout << 0 << " ";
        }
        fout << endl;
    }
}

void mirror(string file, int** pic, int width, int height)
{
    ofstream fout(file);
    fout << "P2" << endl;
    fout << width << " " << height * 2 << endl;
    fout << "255" << endl;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(j == width - 1)
            {
                fout << pic[i][j];
            }
            else
                fout << pic[i][j] << " ";
        }
        fout << endl;
    }
    for(int i = height - 1; i >= 0; i--)
    {
        for(int j = 0; j < width; j++)
        {
            if(j == width - 1)
            {
                fout << pic[i][j];
            }
            else
                fout << pic[i][j] << " ";
        }
        fout << endl;
    }
}

void merge(string file, int** pic1, int** pic2, int width, int height)
{
    ofstream fout(file);
    fout << "P2" << endl;
    fout << width << " " << height << endl;
    fout << "255" << endl;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(j == width - 1)
            {
                fout << (pic1[i][j] + pic2[i][j]) / 2;
            }
            else
                fout << (pic1[i][j] + pic2[i][j]) / 2 << " ";
        }
        fout << endl;
    }
}

void rotate(string file, int** pic, int width, int height)
{
    ofstream fout(file);
    fout << "P2" << endl;
    fout << height << " " << width << endl;
    fout << "255" << endl;

    int** rot = new int*[width];
    for(int i = 0; i < width; i++)
    {
        rot[i] = new int[height];
    }
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            rot[i][j] = pic[j][width-i-1];
        }
    }


    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if(j == height - 1)
            {
                fout << rot[i][j];
            }
            else
                fout << rot[i][j] << " ";
        }
        fout << endl;
    }
}

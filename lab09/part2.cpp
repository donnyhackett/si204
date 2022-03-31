#include <iostream>
#include <fstream>
using namespace std;

int** readPGM(string, int, int, istream&);
void writePGM(string, int**, int, int);
void posterize(string, int**, int, int);
void mirror(string, int**, int, int);

int main()
{
    cout << "filename: ";
    string file;
    cin >> file;
    cout << "output filename: ";
    string outfile;
    cin >> outfile;
    ifstream fin(file);
    string temp;
    int width, height;
    fin >> temp >> width >> height >> temp;
    int** pic = readPGM(file, width, height, fin);
    
    //writePGM(outfile, pic, width, height);
    

    mirror(outfile, pic, width, height);
    
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


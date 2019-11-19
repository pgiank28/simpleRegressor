#include <iostream>
#include <fstream>
#include <sstream>
#include "regressor.h"

int main(int argc,char** argv){
    ifstream myfile ("ex1");
    string sline;
    dot arrayOfContents = (dot)malloc(sizeof(struct point));
    dot arr = (dot)malloc(80*sizeof(struct point));

    int ptr=0;
    if (myfile.is_open())
    {
        while ( getline (myfile,sline) )
        {

        //arrayOfContents = readTupple(sline,arrayOfContents);
        arr[ptr] = *readTupple(sline,arrayOfContents);

        ptr=ptr+1;
        cout << sline << " \n";
        }
    myfile.close();
    }

    else {
        std::cout << "Unable to open file" << "\n";
    }

    line lined = (line)malloc(sizeof(struct cline));


    lined->a=std::stof(string(argv[1]));
    lined->b=std::stof(string(argv[2]));
    lined->c=std::stof(string(argv[3]));

    float vd = verticalDistance(&arr[0],lined);

    cout << vd << " \n";
    free(arr);
    free(arrayOfContents);
    return 0;
}

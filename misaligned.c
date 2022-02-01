#include <stdio.h>
#include <assert.h>
#include <string.h>

 const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
 const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

 typedef struct
 {
     int PairNumber;
     char majorColor[5];
     char minorColor[5];     
 }ColorData;

int printColorMap() 
{  
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) 
        {
           PrintColorMap_test(i,j);
        }
    }
    return i * j;
}

ColorData PrintColorMap_test(int p, int q)
{
    ColorData colormapping;
    printf("%d | %s | %s\n", p * 5 + q, majorColor[p], minorColor[p]);
    /*Copy the strings to their actual structure*/
     colormapping.PairNumber = p * 5 + q;
     strcpy(colormapping.majorColor,majorColor[p]); 
     strcpy(colormapping.minorColor,minorColor[p]);
     return colormapping;    
}

//void PrintColorMap_test(int a, int b)
//{
   // PrintColorMap_main(a,b);
   // colormap = TestPrintColorData(MajorcolorIndex*5 + MinorcolorIndex , majorColor[MajorcolorIndex], minorColor[MinorcolorIndex] );
//}

//ColorData TestPrintColorData(int Pairnum, const char* Major_color, const char* Minor_color)
//{
     //ColorData colormapping;
     /*Copy the strings to their actual structure*/
     //colormapping.PairNumber = Pairnum;
     //strcpy(colormapping.majorColor,Major_color); 
     //strcpy(colormapping.minorColor,Minor_color);
     //return colormapping;    
//}
/* Testing environment */
int main() 
{
    int result = printColorMap();
    int MajorcolorIndex = 2;
    int MinorcolorIndex = 4;
    assert(result == 25);
    ColorData colormap;
    colormap = PrintColorMap_test(MajorcolorIndex,MinorcolorIndex);
    assert(colormap.PairNumber == 14);
    assert(strcmp(colormap.majorColor,"Black") == 0);
    assert(strcmp(colormap.minorColor,"Brown") == 0);
    printf("All is well (maybe!)\n");
    return 0;
}

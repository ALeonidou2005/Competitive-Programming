#include <iostream>

#define N 20

using namespace std;

void PrintArray(int DataArray[]){
    cout<<" =>  ";
    for (int i = 0; i<N; i++){
        cout<<" "<<DataArray[i];
    }
}

int main(){
    system("clear");
    cout<<"\tWelcome to the Bubble Sort Program!!\n";
    
    int j = 0, i, change;
    int DataArray[N] = {34, 5, 2, 44, 24, 6, 17, 18, 9, 29, 25, 10, 7, 38, 36, 40, 32, 4, 11, 27};
    
    cout<<"\nInitial Array Values...\n";
    PrintArray(DataArray);
    
    do{
        j++;
        change = 0;
        for (i = 0; i<N-j; i++){
            if (DataArray[i] > DataArray[i+1]){
                int temp = DataArray[i];
                DataArray[i] = DataArray[i+1];
                DataArray[i+1] = temp;
                change++;
            }
        }
    }while (change != 0);
        
    cout<<"\nSorted In Acsending Order...\n";
    PrintArray(DataArray);
    
    cout<<"\n\n";
    return 0;
}

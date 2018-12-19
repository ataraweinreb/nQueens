#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) { 
   for(int i=0; i<c; i++){ //for loop to check if ok to place queen
       if(q[c]==q[i]) return false; //row test
       if((c-i)==abs(q[c]-q[i])) return false; //diag test
    }
    return true;
}

// This function should return the number of solutions for the given board size (you don't need to print the solutions).
int nqueens(int n) {
   // Dynamically declare an array of size n 
   int *q;
   q=new int[n]; //store in dynamic memory
   q[0]=0; //initialize the first element to 0
   int counter =0; 
   int c=0;
   while(c>=0){ //loop to check cols
       c++;
       if (c==n){ //if you have gone through all the cols
           counter++; //increment counter
           c--; //backtrack to find another solution
       }else{
           q[c]=-1; //start at top of rows
       }
        while(c>=0){ //loop to check rows
            q[c]++; //increment rows
            if(q[c]==n){ //if you went through all rows, backtrack
                c--; 
            } else if(ok(q,c)){
                break;
            }
        }
    }
    delete []q; //delete the array
    return counter; // Return the number of solutions.
}

int main() {
   int n = 12;
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}
   

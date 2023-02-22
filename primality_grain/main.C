#include "hello.decl.h" // created from hello.ci file above
#include <stdlib.h> 
#include <stdio.h> 
#include <iostream>
#include <unistd.h>
#include <cmath>
using namespace std;
/*readonly*/ CProxy_Main mainProxy;
/*mainchare*/
//a
class Main : public CBase_Main
{
    int numComplete = 0;
    int nElem = 0;
    int inputSize = 0;
    pair<long, int> *pairs;
    double st = CkWallTimer();
    public:
    Main(CkArgMsg* m)
    {
        //Start computation
        
        long n = 0;
        /*
        CkPrintf("crap %d\n",sizeof(m->argv)/sizeof(int));
        if (sizeof(m->argv)/sizeof(int) != 3)
        {
            CkPrintf("Enter args: ./charmrun hello num_elements_per_chare num_chares\n");
            CkExit();
        }*/
        nElem =  atoi(m->argv[2]);
        inputSize = atoi(m->argv[1]);
        pairs = new pair<long, int>[nElem*inputSize](); 
        srand (time(NULL));
        CkPrintf("Running Hello on %d processors with %d chares and %d numbers per chare\n", CkNumPes(), nElem, inputSize);
        CProxy_Hello arr = CProxy_Hello::ckNew(nElem); 
        mainProxy = thisProxy;
        for(int i = 0; i < nElem; i++)
        {
            long* slice = (long *)malloc(inputSize * sizeof(long));
            for (int j = 0; j < inputSize; j++)
            {
                n = rand() % 100000000 + 1;
                pairs[i*inputSize+j] = make_pair(n, 0);
                slice[j] = n;
            }
            arr[i].ComputePrimeArray(slice, inputSize);
        }
    };
    void done()
    {
        // Finish computation
        CkPrintf("All done.\n");
        CkExit();
    };
    void recv(long n, int ind, int numarr, int res)
    {
        // Finish computation
        numComplete++;
        //CkPrintf("Received %d from worker chare: %d, %d chares have finished\n",n,ind,q);
        pairs[ind] = make_pair(pairs[ind*inputSize + numarr].first, res);
        if (numComplete == nElem*inputSize)
        {   
            double ed = CkWallTimer();
            if (nElem < 20000)
            {
                for (int i = 0; i < nElem*inputSize; i++)
                {   
                    CkPrintf("Number: %lld Result: %s\n",pairs[i].first, pairs[i].second?"True":"False");
                }
            }
            
            CkPrintf("Time elapsed: %f\n", ed-st);
            
            mainProxy.done();
        }
    };
};
/*array [1D]*/
class Hello : public CBase_Hello
{

    int isPrime(const long number)
    {
        if(number<=1) 
            return 0;
        for(long i=2; i<(int)(sqrt(number)); i++)
            {
                if(0 == number%i)
                    return 0;
            }
        return 1;
    }
    public:
    Hello() {}
    void ComputePrimeArray(long n[], int inputSize)
    {
        //CkPrintf("%lld\n",n);
        //CkPrintf("PE %d, element %ld says %d's primality is %s.\n", CkMyPe(), thisIndex, n, isPrime(n)?"True":"False");
        for(int i = 0; i < inputSize; i++)
        {
            mainProxy.recv(n[i], thisIndex, i, isPrime(n[i]));
        }
        
        
    }
};
#include "hello.def.h" // created from hello.ci file abov
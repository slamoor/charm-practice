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
    int q = 0;
    int nElem = 0;
    pair<long long, int> *pairs;
    double st = CkWallTimer();
    public:
    Main(CkArgMsg* m)
    {
        //Start computation
        
        long long n = 0;
        nElem =  atoi(m->argv[1]);
        pairs = new pair<long long, int>[nElem]();
        srand (time(NULL));
        CkPrintf("Running Hello on %d processors with %d elements.\n", CkNumPes(), nElem);
        CProxy_Hello arr = CProxy_Hello::ckNew(nElem); 
        mainProxy = thisProxy;
        for(int i = 0; i < nElem; i++)
        {
            n = rand() % 100000000 + 1;
            pairs[i] = make_pair(n, 0);
            arr[i].SayHi(n);
        }
    };
    void done()
    {
        // Finish computation
        CkPrintf("All done.\n");
        CkExit();
    };
    void recv(long long n, int ind, int res)
    {
        // Finish computation
        q++;
        //CkPrintf("Received %d from worker chare: %d, %d chares have finished\n",n,ind,q);
        pairs[ind] = make_pair(pairs[ind].first, res);
        if (q == nElem)
        {   
            double ed = CkWallTimer();
            if (nElem < 20000)
            {
                for (int i = 0; i < nElem; i++)
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

    int isPrime(const long long number)
    {
        if(number<=1) 
            return 0;
        for(long long i=2; i<(int)(sqrt(number)); i++)
            {
                if(0 == number%i)
                    return 0;
            }
        return 1;
    }
    public:
    Hello() {}
    void SayHi(long long n)
    {
        //CkPrintf("%lld\n",n);
        //CkPrintf("PE %d, element %ld says %d's primality is %s.\n", CkMyPe(), thisIndex, n, isPrime(n)?"True":"False");
        mainProxy.recv(n, thisIndex, isPrime(n));
        
    }
};
#include "hello.def.h" // created from hello.ci file abov
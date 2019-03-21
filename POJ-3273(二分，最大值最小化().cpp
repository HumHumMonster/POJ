/*
POJ-3273(二分).cpp
输入n与m
一个数组长度为n
将数组分成m段，求m段的字段和的最大值的最小值是多少
*/


#include <stdio.h>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <iterator>
#include <set>
using namespace std ;
#define LL long long
const double PI = acos(-1.0) ;
const double eps = 1e-8 ;

inline LL _max(LL a , LL b){return a > b ? a : b ;}

const int maxn = 1e5 + 10 ;
int n , m ;
LL num[maxn] ;
LL sum = 0 ;

LL maxx = 0 ;

bool check(LL x)
{
    LL now = 0 ;
    int res = 0 ;
    for (int i = 1 ; i <= n ; ++i)
    {
        now += num[i] ;
        if (now > x)
        {
            now = num[i] ;
            ++res ;
        }
    }
    ++res ;
    if (res <= m)
        return true ;
    else
        return false ;
}

int main ()
{
    scanf ("%d%d" , &n , &m) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%lld" , &num[i]) ;
        sum += num[i] ;
        maxx = _max(maxx , num[i]) ;
    }
    LL l = maxx , r = sum ;
    LL res ;
    while (l <= r)
    {
        LL mid = (l + r) >> 1 ;
        if (check(mid))
        {
            r = mid - 1 ;
            res = mid ;
        }
        else
        {
            l = mid + 1 ;
        }
    }
    printf ("%lld" , res) ;
}

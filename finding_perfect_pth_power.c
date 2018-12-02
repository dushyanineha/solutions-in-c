#include<stdio.h>
#include<math.h>
double calcLPPForInteger(double result)
{
double largestPerfectPower = 1;
double base, res;
int exponent;

//result is a positive integer
if(result > 0)
{
base=2;
while(base<=sqrt(result))
{
exponent = 2;
res = pow(base,exponent);
while(exponent<=result)
{
printf("res:%lf\n",res);
if(res > result)
{
break;
}
if(res == result)
{
return exponent;
}
exponent++;
res = pow(base, exponent);
}
base++;
}
return largestPerfectPower;
}
//result is a negative integer
if(result < 0)
{
base = -2;
while(base>=-sqrt(fabs(result)))
{
exponent = 3;
￼res = pow(base,exponent);
while(exponent<=fabs(result))
{
printf("res:%lf\n",res);
if(res < result)
{
break;
}
if(res == result)
{
return exponent;
}
exponent+=2;
res = pow(base, exponent);
}
base--;
}
return largestPerfectPower;
}
}

double calculateLargestPerfectPower(double result)
{
if(result==1 || result==-1 || result==0)return 1;

int n =result,cnt=0,zerosToBeMultiplied, tens;
while(n != 0)
{
n /= 10;
++cnt;
}
//printf("cnt: %d\n",cnt);
if(cnt>9)
zerosToBeMultiplied = cnt - 10;
else if(result>2147 || result<-2147)
zerosToBeMultiplied = 9 - cnt; 
else
zerosToBeMultiplied = 6;

tens = pow(10,zerosToBeMultiplied);
//printf("ppResult: %lf\n",result * tens);
double pResult = result * tens;
￼//printf("pResult: %lf\n",pResult);
int integralPart = pResult/tens;
int floatingPart = abs((int)pResult%tens);

if(floatingPart==0) return calcLPPForInteger(result);

int num = floatingPart;
int count = 0;
if(floatingPart!=0)
{
while(num >= 0)
{
if(num%10 == 0)
{
count++;
num = num / 10;
}
else
{ 
break;
}
}
}
//printf("count: %d",count);
if(count!=0) floatingPart/=pow(10,count);
//printf("Integral Part : %d Floating Part : %d",integralPart, floatingPart);

int numerator,denominator;
if(count!=0) numerator=pResult/pow(10,count);
int nm=numerator, digitsCnt = 0;
while(nm!=0)
{
nm/=10;
++digitsCnt;
}
int im=integralPart, imDigitsCnt = 0;
while(im!=0)
{
im/=10;
++imDigitsCnt;
}
//numerator = (abs(integralPart)*pow(10,digitsCnt))+floatingPart;
￼//if(integralPart<0)numerator = -numerator;
denominator = pow(10,digitsCnt-imDigitsCnt);
printf("Numerator: %d\n",numerator);
printf("Denominator: %d\n",denominator);
int base=2, exponent, res, base2, res2;
while(base<=sqrt(denominator))
{
exponent = 2;
res = pow(base,exponent);
while(exponent<=denominator)
{
if(res>denominator)
{
break;
}
if(res==denominator)
{
if(numerator>0)
{
base2 =2;
while(base2<=sqrt(numerator))
{
res2 = pow(base2,exponent);
if(res2==numerator)
{
//printf("base2: %d\n", base2);
return exponent;
}
base2++;
}
}
else if(numerator<0)
{
if(exponent%2!=0)
{
base2 = -2;
while(base2>=sqrt(numerator))
{
res2 = pow(base2,exponent);
if(res2==numerator)
{
return exponent;
￼}
base2--;
}
}
}
}
exponent++;
res = pow(base,exponent);
}
base++;
}
return 1;
}
int main()
{
double result;
printf("Enter a number:\n");
scanf("%lf",&result);

int y;
y = calculateLargestPerfectPower(result);
printf("Output: %d\n", y);
return 0;
}

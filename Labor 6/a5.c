#define PI 3.1415

int amirPow(int x,int n)
{
    int i;
    int number = 1;

    for (i = 0; i < n; ++i)
        number *= x;

    return(number);
}

void sphere(int r, double *v, double *s) {
    *v = ((4.0/3.0) * PI) * amirPow(r, 3);
    *s = 4.0 * PI * amirPow(r, 2);
}

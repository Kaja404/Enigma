#include <iostream>
#include <conio.h>
#include <stdio.h>


int n;
struct Wirnik
{
    int i_notchy;
    int* notche;
    int* perm;
};

void Utworz(Wirnik* a, int size, bool x)
{
    if (x)
        a->perm = new int[size];
    else
        a->notche = new int[size];
}
int Index(int c, int w)
{
    if ((c + w - 2) >= n) return (c + w - 2 - n);
    else return (c + w - 2);
}

int main()
{
    int  m, l, p, k, cyfra, tmp, * refl, z, z2;
    bool zmiana;
    scanf("%i", &n);
    scanf("%i", &m);
    struct Wirnik* wirniki = new Wirnik[m];
    for (int i = 0; i < m; i++)
    {
        Utworz(&wirniki[i], n, true);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &(wirniki[i].perm[j]));
            wirniki[i].perm[j] -= (1 + j);
        }
        scanf("%d", &(wirniki[i].i_notchy));
        if (wirniki[i].i_notchy != 0)
        {
            Utworz(&wirniki[i], wirniki[i].i_notchy, false);
            for (int j = 0; j < wirniki[i].i_notchy; j++)
            {
                scanf("%d", &(wirniki[i].notche[j]));
            }
        }
    }
    scanf("%i", &l);
    int** reflektory = new int* [l];
    for (int i = 0; i < l; i++)
    {
        reflektory[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &(reflektory[i][j]));
            reflektory[i][j] -= (1 + j);
        }
    }
    scanf("%i", &p);
    for (int i = 0; i < p; i++)
    {
        z = 0;
        z2 = 0;
        zmiana = false;
        scanf("%i", &k);
        int* wirn = new int[k];
        struct Wirnik** wsk_wirn = new Wirnik * [k];
        for (int j = 0; j < k; j++)
        {

            scanf("%d", &tmp);
            wsk_wirn[j] = &wirniki[tmp];
            scanf("%d", &wirn[j]);
        }
        scanf("%i", &tmp);
        refl = &reflektory[tmp][0];
        while (1)
        {
            scanf("%d", &cyfra);
            if (cyfra == 0)
                break;
            else {
                wirn[0]++;
                if (wirn[0] == n + 1)
                    wirn[0] = 1;
                if (z != 0)
                {                    
                    if (k > 1)
                    {
                        if ((z2!=0)&&(k>2))
                        {
                            for (int w = 0; w < wsk_wirn[1]->i_notchy; w++)
                            {
                                if (wirn[1] + 1 == n + 1)
                                {
                                    if (1 == wsk_wirn[1]->notche[w])
                                    {
                                        wirn[2]++;
                                        if (wirn[2] == n + 1)
                                            wirn[2] = 1;
                                        zmiana = true;
                                        break;
                                    }
                                }
                                else
                                {
                                    if (wirn[1] + 1 == wsk_wirn[1]->notche[w])
                                    {
                                        wirn[2]++;
                                        if (wirn[2] == n + 1)
                                            wirn[2] = 1;
                                        zmiana = true;
                                        break;
                                    }
                                }                               
                            }
                        }
                        for (int w = 0; w < wsk_wirn[0]->i_notchy; w++)
                        {
                                if (wirn[0] == wsk_wirn[0]->notche[w])
                                {
                                    zmiana = true;
                                    break;
                                }
                        }
                        if (zmiana)
                        {
                            wirn[1]++;
                            if (wirn[1] == n + 1)
                                wirn[1] = 1;
                            zmiana = false;
                            z2++;
                        }
                        
                    }
                }
                for (int j = 0; j < k; j++)
                {
                   
                    cyfra += wsk_wirn[j]->perm[Index(cyfra,wirn[j])];
                    if (cyfra <= 0)cyfra += n;
                    else if (cyfra > n)cyfra -= n;
                }
                cyfra += *(refl + (cyfra - 1));
                if (cyfra <= 0)cyfra += n;
                else if (cyfra > n)cyfra -= n;
                for (int x = k - 1; x >= 0; x--)
                {
                    int y;
                    if (cyfra < n / 2)y = 1;
                    else y = n;
                    while (1)
                    {
                        
                        if ((wsk_wirn[x]->perm[Index(y, wirn[x])] + y == cyfra) || (wsk_wirn[x]->perm[Index(y, wirn[x])] + y + n == cyfra) || (wsk_wirn[x]->perm[Index(y, wirn[x])] + y - n == cyfra))
                        {
                            cyfra = y;
                            break;
                        }
                        if (cyfra < n / 2)y++;
                        else y--;
                    }
                }
                printf("%d ", cyfra);

            }
            z++;
        }
        printf("\n");
        delete[] wirn;
        for (int e = 0; e < k; e++)
        {
            delete[] wsk_wirn[e];
        }
        delete[] wsk_wirn;
    }
    
    return 0;
}
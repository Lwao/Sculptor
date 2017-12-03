FACE SUPERIOR{

unsigned j(1), count(0);

for (unsigned i=0; i<=1; i++)
{
    if(count==2)
    {
        for(unsigned k=1; k>=0; k--)
        {
            cout << EXT[i].X << EXT[j].Y << EXT[k].Z << endl; 
            count--;
        }
    }
    if(count==0)
    {
        for(unsigned k=0; k<=1; k++)
        {
            cout << EXT[i].X << EXT[j].Y << EXT[k].Z << endl; 
            count++;
        }
    }
}

FACE INFERIOR

unsigned j(0), count(2);

for (unsigned i=0; i<=1; i++)
{
    if(count==2)
    {
        for(unsigned k=1; k>=0; k--)
        {
            cout << EXT[i].X << EXT[j].Y << EXT[k].Z << endl; 
            count--;
        }
    }
    if(count==0)
    {
        for(unsigned k=0; k<=1; k++)
        {
            cout << EXT[i].X << EXT[j].Y << EXT[k].Z << endl; 
            count++;
        }
    }
}

FACE DIREITA

unsigned i(1), count(0);

for (unsigned j=1; j>=0; j--)
{
    if(count==2)
    {
        for(unsigned k=1; k>=0; k--)
        {
            cout << EXT[i].X << EXT[j].Y << EXT[k].Z << endl; 
            count--;
        }
    }
    if(count==0)
    {
        for(unsigned k=0; k<=1; k++)
        {
            cout << EXT[i].X << EXT[j].Y << EXT[k].Z << endl; 
            count++;
        }
    }
}

FACE ESQUERDA

unsigned i(0), count(2);

for (unsigned k=0; k<=1; k++)
{
    if(count==2)
    {
        for(unsigned j=1; j>=0; j--)
        {
            cout << EXT[i].X << EXT[j].Y << EXT[k].Z << endl; 
            count--;
        }
    }
    if(count==0)
    {
        for(unsigned j=0; j<=1; j++)
        {
            cout << EXT[i].X << EXT[j].Y << EXT[k].Z << endl; 
            count++;
        }
    }
}

FACE FRENTE

unsigned k(1), count(2);

for (unsigned i=0; i<=1; i++)
{
    if(count==2)
    {
        for(unsigned j=1; j>=0; j--)
        {
            cout << EXT[i].X << EXT[j].Y << EXT[k].Z << endl; 
            count--;
        }
    }
    if(count==0)
    {
        for(unsigned j=0; j<=1; j++)
        {
            cout << EXT[i].X << EXT[j].Y << EXT[k].Z << endl; 
            count++;
        }
    }
}

FACE TRÁS

unsigned k(0), count(0);

for (unsigned j=1; j>=0; j--)
{
    if(count==2)
    {
        for(unsigned i=1; i>=0; i--)
        {
            cout << EXT[i].X << EXT[j].Y << EXT[k].Z << endl; 
            count--;
        }
    }
    if(count==0)
    {
        for(unsigned i=0; i<=1; i++)
        {
            cout << EXT[i].X << EXT[j].Y << EXT[k].Z << endl; 
            count++;
        }
    }
}


ALGORITMO DE PERCORRER OS VÉRTICES EM SEQUÊNCIA PARA O VECTOR DE VÉRTICES

unsigned count(0);

for (unsigned i=0; i<=1; i++)
{
    for (unsigned j=1; j>=0; j--)
    {
        if(count==2)
        {
            for(unsigned k=1; k>=0; k--)
            {
                cout << EXT[i].X << EXT[j].Y << EXT[k].Z << endl; 
                count--;
            }
        }
        if(count==0)
        {
            for(unsigned k=0; k<=1; k++)
            {
                cout << EXT[i].X << EXT[j].Y << EXT[k].Z << endl; 
                count++;
            }
        }
    }
}






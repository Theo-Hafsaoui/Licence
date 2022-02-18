int Partionner(liste t, uint p, uint r){
  int x=t.t[p];
  int i=p;
  int j=r;
  while (t.t[j]>x)
  {
    j--;
  }
  while (i<j)
  {
    swap(t.t,i,j);
    do
    {
      j--;
    } while (t.t[j]>x);
    do
    {
      i++;
    } while (t.t[i]<x);
  }
  return j;
}

void TriRapide(liste L, uint p, uint r){
  if (p<r)
  {
    q=Partionner(L,p,r);
    TriRapide(L,p,q);
    TriRapide(L,q+1,r);
  }
}


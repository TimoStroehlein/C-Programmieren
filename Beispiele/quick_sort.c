/*
3   17  68  24  72  11  96  28  34  19  86  18  7   26  54
                            28 = Median
-> größer                                       kleiner <-
        26 mit                                      68 tauschen
                7 mit                          72 tauschen
                        18 mit              96 tauschen
                            19 mit  28 tauschen
                            28 mit 34 tauschen

3   17  26  24  7   11  18  19  28  34  86  96  72  68  54
        19                  26
            18          24
*/
void quicksort (*feld, links, rechts)
{
  int ili, ire, med;
  ili = links, ire = rechts;
  med = (links + rechts) / 2;
  while (ili < ire)
  {
    while (feld[ili] < feld[med])
    {
      ili++;
    }
    while (feld[ire] > feld[med])
    {
      ire--;
    }
    tausche feld[ili], feld[ire];
    if (ili == med)
    {
      med = ire;
    }
    else if (ire == med)
    {
      med = ili;
    }
    if (ili < med)
    {
      ili++;
    }
    if (ire > med)
    {
      ire--;
    }
  }
  if (links < med-1)
  {
    quicksort(*feld, links, med-1);
  }
  if (rechts > med+1)
  {
    quicksort(*feld, med+1, rechts);
  }
}

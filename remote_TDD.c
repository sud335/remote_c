#include<stdio.h>
#include<stdlib.h>
void main()
{
    int blocked[10000],heviews[10000],canview[10000],totalview[10000],up,low,nob,nov,n,noc,i,j,k;
    int fl=0,fl1=0,temp=0,temp2=0,temp3=0,count1=0,count2=0,fcount3=0,bcount3=0,count4=0,backcount=0,curr,prev,mincountfb=0;
    int least=0;
    scanf("%d",&low);
    scanf("%d",&up);
    if((low<=0)||(low>10000)||(low>up)||(up>10000))
    {
        printf("\n Error input(low>0 and low<=10000)&&(low<=high)&&(high<=10000)");

        exit(1);
    }
    j=0;
    for(i=low;i<=up;i++)
    {
        totalview[j]=i;

        j++;
    }
    n=j;
    scanf("%d",&nob);
    for(i=0;i<nob;i++)
    {
        scanf("%d",&blocked[i]);
    }
    for(i=0;i<nob;i++)
    {
        if((blocked[i]<low)||(blocked[i]>up))
        { fl1=1;
        break;
        }

    }
    if((nob>40)||(fl1==1)||(nob<0))
    {
        printf("\n Error input (no of blocked channels<=40) or blocked[i]>up or blocked[i]<low");

        exit(1);
    }
    fl=0;
    scanf("%d",&nov);
    for(i=0;i<nov;i++)
    {
        scanf("%d",&heviews[i]);
    }
    for(i=0;i<nov;i++)
    {
        if((heviews[i]<low)||(heviews[i]>up))
        {
            fl1=1;
            break;
        }

    }
    if((nov>50)||(fl1==1)||(nov<0))
    {
        printf("\n Error input (no of view channels<=40) or heviews[i]>up or heviews[i]<low");

        exit(1);
    }
    fl=0;
    k=0;
    for(i=0;i<n;i++)
    {
        fl=0;
        for(j=0;j<nob;j++)
        {
            if(totalview[i]==blocked[j])
            {
                fl=1;
                break;
            }

        }
        if(fl!=1)
        {
            canview[k]=totalview[i];
            k++;
        }
    }
    noc=k;
    fl=0;
    for(i=0;i<nov;i++)
    {
        for(k=0;k<nob;k++)
        {
            if(blocked[k]==heviews[i])
            {
                fl=1;
                break;
            }
        }
        if(fl==1)
        {
           printf("\n Error input cant view the blocked channel %d",heviews[i]);
           exit(1);
        }

    }

    fl=0;
    for(i=0;i<nov;i++)
    {
        if(i==0)
        {
            temp=heviews[i];

            while(temp!=0)
            {
                temp=temp/10;
                ++count1;

            }
        }
        else
        {
            backcount=0;
            if(abs(heviews[i]-heviews[i-1])==1)
            {
                ++count1;

            }
            else if(heviews[i]==heviews[i-2])
            {
                backcount=1;
                count1++;

            }
            else if(heviews[i]==heviews[i-1])
            {
                /*do nothing*/
            }
            else
            {
                count2=0;

                temp2=heviews[i];

                while(temp2!=0)
                {
                    temp2=temp2/10;
                    ++count2;
                }
                curr=heviews[i];
                prev=heviews[i-1];
                fcount3=0;
                bcount3=0;
                for(j=0;j<noc;j++)
                {
                    if(curr==canview[j])
                    {
                            temp3=j;
                            break;
                    }
                }
                for(k=temp3;k<=noc;k++)
                {
                    if(k==noc)
                    {
                        k=0;

                    }
                    if(prev==canview[k])
                    {
                        break;
                    }
                    fcount3++;
                }
                for(k=temp3;k>=0;k--)
                {

                    if(prev==canview[k])
                    {
                        break;
                    }
                    if(k==0)
                    {
                        k=noc;

                    }

                    bcount3++;
                }

                if(fcount3<bcount3)
                    mincountfb=fcount3;
                else
                    mincountfb=bcount3;
                count4=noc;
                if(abs(heviews[i]-heviews[i-2])==1)
                    count4=2;
                else if(abs(heviews[i]-heviews[i-2])==2)
                    count4=3;
                if((count2<=mincountfb) && (count2<=count4))
                {
                    least = count2;
                }
                else if((mincountfb<=count2)&&(mincountfb<=count4))
                {
                    least=mincountfb;
                }
                else if((count4<count2)&&(count4<mincountfb))
                {
                    least=count4;
                }
                count1+=least;
            }

        }

    }

    printf("\n%d",count1);
}


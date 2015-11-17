//log on 19th may 7:08pm
//log on 20th may 10:36am
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int blocked[10000],heviews[10000],canview[10000],totalview[10000],up,low,nob,nov,n,noc,i,j,k;
    int fl=0,fl1=0,temp=0,temp2=0,temp3=0,chkcount=1,count1=0,count2=0,fcount3=0,bcount3=0,count4=0,backcount=0,curr,prev,mincountfb=0;
    int least=0;
    //---------------------------------
    printf("Enter the lower <tab/two space> upper limit  : ");
    scanf("%d",&low);
    scanf("%d",&up);
    //constrain1 low>0 and low<=10000
    if((low<=0)||(low>10000)||(low>up)||(up>10000))
    {
        printf("\n Error input(low>0 and low<=10000)&&(low<=high)&&(high<=10000)");
        getch();
        exit(0);
    }
    j=0;
    //---------------------------------
    for(i=low;i<=up;i++)
    {
        totalview[j]=i;

        j++;
    }
    n=j;

    //----------------------------------

    printf("Enter the no of blocked <tab/two space>blocked channels:");
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
        getch();
        exit(0);
    }

    //---------------------------------
    fl=0;
    printf("Enter the noofview <tab/two space> viewing channels:");
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
    if((nov>50)||(fl1==1)||(nov<0))//constrains for viewing channels
    {
        printf("\n Error input (no of view channels<=40) or heviews[i]>up or heviews[i]<low");
        getch();
        exit(0);
    }

    //----------------------------------
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
            canview[k]=totalview[i];//has all the channels that he can view or queue
            k++;
        }
    }
    noc=k;

    //--------------------------------------------------------------------------------
    fl=0;
    for(i=0;i<nov;i++)//to check if he views the blocked channels
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


    printf("\n\n\nNow, Gaurav can view these channels: \n");
    for(i=0;i<noc;i++)
    {
        printf("%d \t",canview[i]);
    }


    //--------------------------------------------------------------------------------------


    for(i=0;i<nov;i++)
    {
        if(i==0)//intial count of number
        {
            temp=heviews[i];

            while(temp!=0)
            {
                temp=temp/10;
                ++count1;

            }
            printf("\n\nTo go to the initial channel ,Gaurav clicks \"%d\" button,So Now the count will be %d",heviews[i],count1);
        }
        else
        {
            backcount=0;
            if(abs(heviews[i]-heviews[i-1])==1)//if the difference of channel is 1. So he can press up or down button
            {
                ++count1;
                printf("\n\nHe then Clicks up/down button to reach \"%d\",So Now the count will be \"%d\"",heviews[i],count1);
            }
            //back button
            else if(heviews[i]==heviews[i-2])
            {
                backcount=1;
                count1++;

                printf("\n\nHe then Clicks Back button to reach \"%d\",So Now the count will be \"%d\"",heviews[i],count1);

            }
            else if(heviews[i]==heviews[i-1])//When the previous channel he views is same as current channel
            {
                /*do nothing*/
            }
            else
            {
                count2=0;

                temp2=heviews[i];
                printf("\n\n\nThere are now four ways to reach \"%d\" channel:",heviews[i]);

                //1st way
                while(temp2!=0)
                {
                    temp2=temp2/10;
                    ++count2;// counts the digits in the number value. So he can directly press the number.
                }
                printf("\n\nHe can Directly click \"%d\",Then the count will be \"%d\"",heviews[i],count2);
                //--------------------------------

                //2nd way

                //forward movement
                curr=heviews[i];
                prev=heviews[i-1];
                fcount3=0;
                bcount3=0;
                for(j=0;j<noc;j++)//to find the index element where current view channel will be present.
                {
                    if(curr==canview[j])
                    {
                            temp3=j;
                            break;
                    }
                }


                for(k=temp3;k<=noc;k++)//presses up button continously and loops back to top.
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

                //printf("\n\n%d forwardcount\n",fcount3);

                printf("\n\nOR he can click down button continuosly(loop) to reach \"%d\",Then the number of steps will be \"%d\"",heviews[i],fcount3);


                //backward movement
                for(k=temp3;k>=0;k--)//presses down button continously and loops back to last.
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
                //printf("\n\n%d backwordcount\n",bcount3);
                printf("\n\nOR he can click up button continuosly(loop) to reach \"%d\",Then the number of steps will be \"%d\"",heviews[i],bcount3);

                if(fcount3<bcount3)//minimum for forward or backward traversal.
                    mincountfb=fcount3;
                else
                    mincountfb=bcount3;
                //printf("\n HELLO %d Minimum Count FB\n",mincountfb);


                //
                //
                //
                //pressing back+up/down button
                count4=noc;

                if(abs(heviews[i]-heviews[i-2])==1)//for values like 998 1 999 or 9999 1 10000
                    count4=2;
                else if(abs(heviews[i]-heviews[i-2])==2)//for values like 9999  1   9997
                    count4=3;
                //i also did another algorithm but this is efficient given the constrains

                //printf("%d back+up/down",count4);

                printf("\n\nOR he can click back+up/down continuosly(loop) to reach \"%d\",Then the number of steps will be \"%d\"",heviews[i],count4);


                //Least of the count2(numerical),mincountfb(rotating) and count4(back+up/down)
                least=0;
                if((count2<=mincountfb)&& (count2<=count4))
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
                printf("\n\nThus, the minimum of four cases is \"%d\" , And Now the count will be %d",least,count1);

            }

        }

    }

    printf("\n\n\nThe Minimum steps required to view all Channels is : %d\n\n",count1);
}

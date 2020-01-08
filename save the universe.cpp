using namespace std;

int main()
{
    int n,s,q;
    string search_engine;
    string quire_name;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s>>ws;
        string engine_names[s];
        for(int j=0;j<s;j++)
        {
            getline(cin,search_engine);
            engine_names[j] = search_engine;

        }
        cin>>q>>ws;
        string quires[q];
        for(int k=0;k<q;k++)
        {
            getline(cin,quire_name);
            quires[k] = quire_name;
        }
        int last_line[10];
        int first_line[10];
        int reapted[10];
        int counter =0;
        for(int j=0;j<s;j++)
        {
            counter = 0;
            for(int k=0;k<q;k++)
            {
                if(engine_names[j]==quires[k])
                {
                    counter++;
                    last_line[j] = k;
                    if(counter ==1)
                    {
                        first_line[j]=k;
                    }

                }

            }
            reapted[j] = counter;


        }
        string engine_in_use;
        bool reaptation = true;
        int switch_engine = 0;
        for (int j=0;j<s;j++)
        {
           if(reapted[j]==0)
           {
            reaptation = false;
           }

        }
        for(int j=0;j<s;j++)
        {
        for(int k=j+1;k<s-1;k++)
        {
            if(first_line[j]<first_line[k])
            {
                swap(first_line[j],first_line[k]);
                swap(engine_names[j],engine_names[k]);
                swap(reapted[j],reapted[k]);
            }

        }
        }
        if (reaptation == true)
        {
          int e_s=0;
          engine_in_use = engine_names[e_s];
          for(int k=0;k<q;k++)
          {
           if(quires[k]==engine_in_use)
           {
              switch_engine++;
              e_s++;
              engine_in_use = engine_names[e_s];

           }
          }

        }
        else
        {
            switch_engine=0;

        }
        cout<<"Case "<<"#"<<i<<": "<<switch_engine<<endl;


}
        return 0;

}

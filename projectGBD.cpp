#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <iomanip>
#include <tuple>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = 1e9;

string normalize(const string& name) {
    string result;
    for (char c : name) {
        if (isalpha(c) || c == ' ') result += tolower(c);
    }
    if (!result.empty()) result[0] = toupper(result[0]);
    return result;
}

class Graph {
public:
    int vertices = 0;
    unordered_map<string,int> cityToIndex;
    unordered_map<int,string> indexToCity;
    vector<vector<pair<int,int>>> adjacent_list;
    vector<tuple<int,int,int>> edges;
    vector<string> allCities;

    Graph() { adjacent_list.resize(100);
   }

    void addCity(const string &name) {
        string city = normalize(name);
        if(cityToIndex.count(city)) return;
        cityToIndex[city] = vertices;
        indexToCity[vertices] = city;
        allCities.push_back(city);
        vertices++;
        if(vertices > adjacent_list.size())
            adjacent_list.resize(vertices*2);
    }

    void addEdge(const string &from, const string &to, int weight) {
        addCity(from); addCity(to);
        int u = cityToIndex[normalize(from)];
        int v = cityToIndex[normalize(to)];
        adjacent_list[u].push_back({v, weight});
        adjacent_list[v].push_back({u, weight});
        edges.push_back({u,v,weight});
    }

    void printAllCities() {
        sort(allCities.begin(), allCities.end());
        cout << "Available Districts (" << allCities.size() << "):\n";
        int col = 0, COLS = 5;
        for(auto &c : allCities) {
            cout << left << setw(20) << c;
            if(++col % COLS == 0) cout << "\n";
        }
        if(col % COLS) cout << "\n";
    }
};
void loadHardcodedEdges(Graph &G){
G.addEdge("Bagerhat","Khulna",34);
G.addEdge("Bagerhat","Gopalganj",52);
G.addEdge("Bagerhat","Pirojpur",66);
G.addEdge("Bagerhat","Narail",107);
G.addEdge("Bandarban","Chittagong",85);
G.addEdge("Bandarban","Rangamati",74);
G.addEdge("Bandarban","Coxsbazar",121);
G.addEdge("Barguna","Jhalokati",95);
G.addEdge("Barguna","Patuakhali",44);
G.addEdge("Barguna","Pirojpur",96);
G.addEdge("Barguna","Barisal",84);
G.addEdge("Barisal","Jhalokati",19);
G.addEdge("Barisal","Pirojpur",54);
G.addEdge("Barisal","Barguna",84);
G.addEdge("Barisal","Patuakhali",41);
G.addEdge("Barisal","Bhola",36);
G.addEdge("Barisal","Madaripur",64);
G.addEdge("Barisal","Shariatpur",87);
G.addEdge("Bhola","Barisal",36);
G.addEdge("Bhola","Patuakhali",77);
G.addEdge("Bhola","Lakshmipur",198);
G.addEdge("Bhola","Noakhali",233);
G.addEdge("Bogra","Gaibandha",71);
G.addEdge("Bogra","Joypurhat",52);
G.addEdge("Bogra","Naogaon",50);
G.addEdge("Bogra","Natore",68);
G.addEdge("Bogra","Sirajganj",72);
G.addEdge("Brahmanbaria","Cumilla",81);
G.addEdge("Brahmanbaria","Narsingdi",67);
G.addEdge("Brahmanbaria","Kishoreganj",79);
G.addEdge("Brahmanbaria","Habiganj",80);
G.addEdge("Brahmanbaria","Narayanganj",107);
G.addEdge("Chandpur","Cumilla",67);
G.addEdge("Chandpur","Noakhali",78);
G.addEdge("Chandpur","Lakshmipur",43);
G.addEdge("Chandpur","Munshiganj",128);
G.addEdge("Chandpur","Shariatpur",62);
G.addEdge("Chittagong","Feni",93);
G.addEdge("Chittagong","Khagrachari",117);
G.addEdge("Chittagong","Rangamati",78);
G.addEdge("Chittagong","Bandarban",85);
G.addEdge("Chittagong","Coxsbazar",160);
G.addEdge("Chuadanga","Jhenaidah",37);
G.addEdge("Chuadanga","Kushtia",49);
G.addEdge("Chuadanga","Meherpur",26);
G.addEdge("Coxsbazar","Chittagong",160);
G.addEdge("Coxsbazar","Bandarban",121);
G.addEdge("Cumilla","Brahmanbaria",81);
G.addEdge("Cumilla","Chandpur",67);
G.addEdge("Cumilla","Noakhali",67);
G.addEdge("Cumilla","Feni",58);
G.addEdge("Cumilla","Narayanganj",94);
G.addEdge("Cumilla","Munshiganj",109);
G.addEdge("Dhaka","Manikganj",63);
G.addEdge("Dhaka","Narayanganj",17);
G.addEdge("Dhaka","Munshiganj",27);
G.addEdge("Dhaka","Gazipur",37);
G.addEdge("Dhaka","Tangail",92);
G.addEdge("Dinajpur","Thakurgaon",58);
G.addEdge("Dinajpur","Panchagarh",94);
G.addEdge("Dinajpur","Nilphamari",57);
G.addEdge("Dinajpur","Rangpur",78);
G.addEdge("Faridpur","Rajbari",31);
G.addEdge("Faridpur","Gopalganj",89);
G.addEdge("Faridpur","Madaripur",73);
G.addEdge("Faridpur","Shariatpur",96);
G.addEdge("Faridpur","Manikganj",66);
G.addEdge("Faridpur","Narail",100);
G.addEdge("Feni","Cumilla",58);
G.addEdge("Feni","Chittagong",93);
G.addEdge("Feni","Noakhali",41);
G.addEdge("Gaibandha","Kurigram",120);
G.addEdge("Gaibandha","Rangpur",76);
G.addEdge("Gaibandha","Bogra",71);
G.addEdge("Gaibandha","Jamalpur",243);
G.addEdge("Gaibandha","Joypurhat",77);
G.addEdge("Gazipur","Dhaka",37);
G.addEdge("Gazipur","Mymensingh",93);
G.addEdge("Gazipur","Kishoreganj",99);
G.addEdge("Gazipur","Narsingdi",56);
G.addEdge("Gazipur","Narayanganj",51);
G.addEdge("Gazipur","Tangail",64);
G.addEdge("Gopalganj","Faridpur",89);
G.addEdge("Gopalganj","Madaripur",59);
G.addEdge("Gopalganj","Bagerhat",52);
G.addEdge("Gopalganj","Narail",55);
G.addEdge("Gopalganj","Pirojpur",59);
G.addEdge("Gopalganj","Barisal",117);
G.addEdge("Habiganj","Brahmanbaria",76);
G.addEdge("Habiganj","Kishoreganj",132);
G.addEdge("Habiganj","Sunamganj",137);
G.addEdge("Habiganj","Moulvibazar",63);
G.addEdge("Habiganj","Sylhet",81);
G.addEdge("Jamalpur","Sherpur",16);
G.addEdge("Jamalpur","Mymensingh",57);
G.addEdge("Jamalpur","Tangail",87);
G.addEdge("Jamalpur","Gaibandha",243);
G.addEdge("Jamalpur","Bogra",172);
G.addEdge("Jessore","Jhenaidah",46);
G.addEdge("Jessore","Magura",44);
G.addEdge("Jessore","Narail",34);
G.addEdge("Jessore","Satkhira",72);
G.addEdge("Jessore","Khulna",59);
G.addEdge("Jhalokati","Barisal",19);
G.addEdge("Jhalokati","Pirojpur",33);
G.addEdge("Jhalokati","Patuakhali",52);
G.addEdge("Jhalokati","Barguna",95);
G.addEdge("Jhenaidah","Kushtia",46);
G.addEdge("Jhenaidah","Chuadanga",37);
G.addEdge("Jhenaidah","Jessore",46);
G.addEdge("Jhenaidah","Magura",28);
G.addEdge("Jhenaidah","Rajbari",103);
G.addEdge("Joypurhat","Naogaon",39);
G.addEdge("Joypurhat","Bogra",52);
G.addEdge("Joypurhat","Gaibandha",77);
G.addEdge("Joypurhat","Dinajpur",89);
G.addEdge("Khagrachari","Chittagong",117);
G.addEdge("Khagrachari","Rangamati",70);
G.addEdge("Khulna","Bagerhat",34);
G.addEdge("Khulna","Satkhira",59);
G.addEdge("Khulna","Jessore",59);
G.addEdge("Khulna","Narail",90);
G.addEdge("Kishoreganj","Narsingdi",75);
G.addEdge("Kishoreganj","Brahmanbaria",79);
G.addEdge("Kishoreganj","Habiganj",132);
G.addEdge("Kishoreganj","Mymensingh",68);
G.addEdge("Kishoreganj","Netrokona",65);
G.addEdge("Kishoreganj","Sunamganj",266);
G.addEdge("Kishoreganj","Gazipur",99);
G.addEdge("Kurigram","Lalmonirhat",29);
G.addEdge("Kurigram","Gaibandha",120);
G.addEdge("Kurigram","Rangpur",56);
G.addEdge("Kurigram","Jamalpur",323);
G.addEdge("Kushtia","Meherpur",73);
G.addEdge("Kushtia","Chuadanga",49);
G.addEdge("Kushtia","Jhenaidah",46);
G.addEdge("Kushtia","Rajbari",65);
G.addEdge("Kushtia","Pabna",49);
G.addEdge("Kushtia","Natore",76);
G.addEdge("Kushtia","Rajshahi",122);
G.addEdge("Lakshmipur","Bhola",162);
G.addEdge("Lakshmipur","Noakhali",35);
G.addEdge("Lakshmipur","Chandpur",43);
G.addEdge("Lalmonirhat","Kurigram",29);
G.addEdge("Lalmonirhat","Nilphamari",106);
G.addEdge("Lalmonirhat","Rangpur",51);
G.addEdge("Madaripur","Gopalganj",59);
G.addEdge("Madaripur","Shariatpur",23);
G.addEdge("Madaripur","Faridpur",73);
G.addEdge("Madaripur","Barisal",73);
G.addEdge("Magura","Jhenaidah",28);
G.addEdge("Magura","Jessore",44);
G.addEdge("Magura","Narail",50);
G.addEdge("Magura","Faridpur",52);
G.addEdge("Magura","Rajbari",75);
G.addEdge("Manikganj","Tangail",84);
G.addEdge("Manikganj","Dhaka",63);
G.addEdge("Manikganj","Rajbari",55);
G.addEdge("Manikganj","Faridpur",65);
G.addEdge("Manikganj","Pabna",169);
G.addEdge("Manikganj","Sirajganj",125);
G.addEdge("Meherpur","Chuadanga",26);
G.addEdge("Meherpur","Kushtia",58);
G.addEdge("Moulvibazar","Sylhet",58);
G.addEdge("Moulvibazar","Habiganj",63);
G.addEdge("Munshiganj","Dhaka",27);
G.addEdge("Munshiganj","Narayanganj",15);
G.addEdge("Munshiganj","Chandpur",128);
G.addEdge("Munshiganj","Shariatpur",101);
G.addEdge("Munshiganj","Madaripur",91);
G.addEdge("Munshiganj","Faridpur",102);
G.addEdge("Munshiganj","Cumilla",109);
G.addEdge("Mymensingh","Sherpur",69);
G.addEdge("Mymensingh","Jamalpur",57);
G.addEdge("Mymensingh","Netrokona",39);
G.addEdge("Mymensingh","Gazipur",93);
G.addEdge("Mymensingh","Kishoreganj",68);
G.addEdge("Mymensingh","Tangail",94);
G.addEdge("Naogaon","Natore",97);
G.addEdge("Naogaon","Joypurhat",39);
G.addEdge("Naogaon","Rajshahi",78);
G.addEdge("Naogaon","Bogra",50);
G.addEdge("Naogaon","Nawabganj",98);
G.addEdge("Narail","Magura",50);
G.addEdge("Narail","Jessore",34);
G.addEdge("Narail","Gopalganj",55);
G.addEdge("Narail","Bagerhat",107);
G.addEdge("Narail","Khulna",90);
G.addEdge("Narail","Faridpur",10);
G.addEdge("Narayanganj","Dhaka",17);
G.addEdge("Narayanganj","Munshiganj",15);
G.addEdge("Narayanganj","Narsingdi",49);
G.addEdge("Narayanganj","Cumilla",94);
G.addEdge("Narayanganj","Brahmanbaria",107);
G.addEdge("Narayanganj","Gazipur",51);
G.addEdge("Narsingdi","Gazipur",56);
G.addEdge("Narsingdi","Narayanganj",49);
G.addEdge("Narsingdi","Brahmanbaria",67);
G.addEdge("Narsingdi","Kishoreganj",75);
G.addEdge("Natore","Rajshahi",46);
G.addEdge("Natore","Naogaon",97);
G.addEdge("Natore","Bogra",68);
G.addEdge("Natore","Pabna",59);
G.addEdge("Natore","Kushtia",76);
G.addEdge("Natore","Sirajganj",85);
G.addEdge("Nawabganj","Naogaon",98);
G.addEdge("Nawabganj","Rajshahi",46);
G.addEdge("Netrokona","Mymensingh",39);
G.addEdge("Netrokona","Kishoreganj",65);
G.addEdge("Netrokona","Sunamganj",96);
G.addEdge("Nilphamari","Lalmonirhat",106);
G.addEdge("Nilphamari","Rangpur",50);
G.addEdge("Nilphamari","Dinajpur",57);
G.addEdge("Nilphamari","Panchagarh",68);
G.addEdge("Noakhali","Lakshmipur",35);
G.addEdge("Noakhali","Feni",41);
G.addEdge("Noakhali","Cumilla",67);
G.addEdge("Noakhali","Chandpur",78);
G.addEdge("Pabna","Kushtia",49);
G.addEdge("Pabna","Natore",59);
G.addEdge("Pabna","Sirajganj",91);
G.addEdge("Pabna","Manikganj",169);
G.addEdge("Pabna","Rajbari",114);
G.addEdge("Panchagarh","Thakurgaon",37);
G.addEdge("Panchagarh","Dinajpur",94);
G.addEdge("Panchagarh","Nilphamari",68);
G.addEdge("Patuakhali","Barguna",44);
G.addEdge("Patuakhali","Bhola",77);
G.addEdge("Patuakhali","Barisal",41);
G.addEdge("Pirojpur","Bagerhat",66);
G.addEdge("Pirojpur","Barisal",54);
G.addEdge("Pirojpur","Barguna",96);
G.addEdge("Pirojpur","Gopalganj",59);
G.addEdge("Pirojpur","Jhalokati",33);
G.addEdge("Rajbari","Faridpur",31);
G.addEdge("Rajbari","Jhenaidah",103);
G.addEdge("Rajbari","Magura",75);
G.addEdge("Rajbari","Pabna",114);
G.addEdge("Rajbari","Manikganj",55);
G.addEdge("Rajshahi","Naogaon",78);
G.addEdge("Rajshahi","Kushtia",50);
G.addEdge("Rajshahi","Natore",46);
G.addEdge("Rajshahi","Nawabganj",46);
G.addEdge("Rangamati","Chittagong",78);
G.addEdge("Rangamati","Khagrachari",70);
G.addEdge("Rangamati","Bandarban",74);
G.addEdge("Rangpur","Dinajpur",78);
G.addEdge("Rangpur","Kurigram",56);
G.addEdge("Rangpur","Lalmonirhat",51);
G.addEdge("Rangpur","Nilphamari",50);
G.addEdge("Rangpur","Gaibandha",76);
G.addEdge("Satkhira","Khulna",59);
G.addEdge("Satkhira","Jessore",72);
G.addEdge("Shariatpur","Barisal",87);
G.addEdge("Shariatpur","Madaripur",23);
G.addEdge("Shariatpur","Munshiganj",101);
G.addEdge("Shariatpur","Chandpur",62);
G.addEdge("Sherpur","Jamalpur",16);
G.addEdge("Sherpur","Mymensingh",69);
G.addEdge("Sirajganj","Manikganj",120);
G.addEdge("Sirajganj","Tangail",103);
G.addEdge("Sirajganj","Jamalpur",46);
G.addEdge("Sirajganj","Natore",85);
G.addEdge("Sirajganj","Pabna",91);
G.addEdge("Sirajganj","Bogra",72);
G.addEdge("Sunamganj","Habiganj",137);
G.addEdge("Sunamganj","Netrokona",96);
G.addEdge("Sunamganj","Sylhet",70);
G.addEdge("Sylhet","Habiganj",81);
G.addEdge("Sylhet","Moulvibazar",58);
G.addEdge("Sylhet","Sunamganj",70);
G.addEdge("Tangail","Gazipur",64);
G.addEdge("Tangail","Jamalpur",87);
G.addEdge("Tangail","Mymensingh",94);
G.addEdge("Tangail","Manikganj",84);
G.addEdge("Tangail","Sirajganj",103);
G.addEdge("Tangail","Dhaka",92);
G.addEdge("Thakurgaon","Dinajpur",58);
G.addEdge("Thakurgaon","Panchagarh",37);

}
pair<vector<int>, vector<int>> dijkstra(const Graph &G, int src) {
    vector<int> dist(G.vertices, INF), parent(G.vertices, -1);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,src});
    while(!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(auto &[v,w] : G.adjacent_list[u]) {
            if(dist[u]+w < dist[v]) {
                dist[v] = dist[u]+w;
                parent[v] = u;
                pq.push({dist[v],v});
            }
        }
    }
    return {dist,parent};
}
pair<vector<int>, vector<int>> bellmanFord(const Graph &G, int src) {
    vector<int> dist(G.vertices, INF), parent(G.vertices, -1);
    dist[src] = 0;
    for(int i=0;i<G.vertices-1;i++)
        for(auto &[u,v,w] : G.edges)
            if(dist[u] != INF && dist[u]+w < dist[v])
            {
                 dist[v] = dist[u]+w;
                  parent[v]=u;
            }
       for(auto &[u,v,w] : G.edges)
        if(dist[u]!=INF && dist[u]+w<dist[v]) {
                cout<<"Negative cycle!\n"; return {{}, {}};
        }
    return {dist,parent};
}
pair<vector<int>, vector<int>> floydWarshall(const Graph &G, int src) {
    int V = G.vertices;
    vector<vector<int>> dist(V, vector<int>(V, INF));
    vector<vector<int>> next(V, vector<int>(V,-1));
    for(int i=0;i<V;i++) {
        dist[i][i]=0;
        for(auto &[v,w]:G.adjacent_list[i]) { dist[i][v]=w; next[i][v]=v; }
    }
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                if(dist[i][k]!=INF && dist[k][j]!=INF && dist[i][k]+dist[k][j]<dist[i][j]) {
                    dist[i][j]=dist[i][k]+dist[k][j]; next[i][j]=next[i][k];
                }
    vector<int> distances(V), parents(V,-1);
    for(int v=0;v<V;v++) {
        distances[v]=dist[src][v];
        if(v!=src && dist[src][v]!=INF) {
            int u = src;
            while(u != v) {
                int n = next[u][v];
                parents[n] = u;
                u = n;
            }
        }
    }
    return {distances,parents};
}

void printPath(const vector<int> &parent, int v, const Graph &G, vector<string> &out) {
    if(parent[v]!=-1) printPath(parent,parent[v],G,out);
    out.push_back(G.indexToCity.at(v));
}

void showPathResult(const Graph &G, int src, int dst, const vector<int> &dist, const vector<int> &parent) {
    if(dist.empty())
        { cout<<"Error: Negative cycle.\n"; return; }
    if(dist[dst]==INF)
    {
        cout<<"No path from "<<G.indexToCity.at(src)<<" to "<<G.indexToCity.at(dst)<<"\n"; return;
    }
    vector<string> path;
    printPath(parent,dst,G,path);
    cout<<"\nShortest Distance from "<<G.indexToCity.at(src)<<" to "<<G.indexToCity.at(dst)<<": "<<dist[dst]<<" km\n";
    cout<<"\nRoute:\n";
    for(int i=0;i+1<path.size();i++){
        int u = G.cityToIndex.at(path[i]), v = G.cityToIndex.at(path[i+1]), w=0;
        for(auto &[vv,ww]:G.adjacent_list[u]) if(vv==v) { w=ww; break;
        }
        cout<<left<<setw(20)<<path[i]<<" -> "<<left<<setw(20)<<path[i+1]<<": "<<w<<" km\n";
    }
}

void runAlgorithm(int choice, const Graph &G, int src, int dst)
{
    if(choice==1) { auto r=dijkstra(G,src);
    cout<<"\n[Dijkstra]";
    showPathResult(G,src,dst,r.first,r.second);
     }
    else if(choice==2) { auto r=bellmanFord(G,src);
    cout<<"\n[Bellman-Ford]"; showPathResult(G,src,dst,r.first,r.second);
    }
    else if(choice==3) {
            auto r=floydWarshall(G,src); cout<<"\n[Floyd-Warshall]";
    showPathResult(G,src,dst,r.first,r.second); }
}

int main() {
    Graph G;
    loadHardcodedEdges(G);
    while(true) {
        cout<<"-----------------------------------\n"
            <<"   --< Graph Route Bangladesh >-- \n"
            <<"-----------------------------------\n"
            <<"1. Show all districts\n"
            <<"2. Find shortest path (Dijkstra)\n"
            <<"3. Find shortest path (Bellman-Ford)\n"
            <<"4. Find shortest path (Floyd-Warshall)\n"
            <<"5. Exit\n"
            <<"Enter choice: ";
        int choice; cin>>choice; cin.ignore(numeric_limits<streamsize>::max(),'\n');

        if(choice==1) G.printAllCities();
        else if(choice>=2 && choice<=4) {
            string src,dst;
            cout<<"Source : "; getline(cin,src);
            cout<<"Destination : "; getline(cin,dst);
            src=normalize(src); dst=normalize(dst);
            if(!G.cityToIndex.count(src)||!G.cityToIndex.count(dst))
            {
              cout<<"Invalid district(s)\n"; continue;
            }
            runAlgorithm(choice-1,G,G.cityToIndex[src],G.cityToIndex[dst]);
        }
        else if(choice==5){ cout<<"Goodbye!\n"; break;
        } else cout<<"Invalid choice.\n";
    }
    return 0;
}

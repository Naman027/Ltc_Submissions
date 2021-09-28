class Solution {
public:
    class Point{
public:
    long long x,y,z;

    Point(long long x, long long y, long long z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    bool operator == (Point p){
        return (this->x==p.x && this->y==p.y && this->z==p.z);
    }

    Point operator - (Point b){
        return Point(this->x-b.x,this->y-b.y,this->z-b.z);
    }

    };

    Point cross(Point a, Point b){
        return Point(a.y*b.z-a.z*b.y,a.z*b.x-b.z*a.x,a.x*b.y-b.x*a.y);
    }

    long long signedAreaOfParallelogram(Point a, Point b,Point c){
        // a->b 2nd edge b->c
        //cout << "Difference; " << (b-a).x << " " << (b-a).y << " " << (b-a).z << endl;
        long long val = cross(b-a,c-b).z;
        return val;
    }

    int orientation(Point a,Point b,Point c){
        long long v = signedAreaOfParallelogram(a,b,c);
        //cout << "orientation: " << v << endl;
        if(v<0) return -1;
        if(v>0) return 1;
        return 0;
    }

    long long dot(Point a,Point b){
        return a.x*b.x+a.y*b.y+a.z*b.z;
    }

    vector<Point> convexHullJarvisMarch(vector<Point>& a){
        int n = a.size();
        int st = 0;
        for(int i=1;i<n;i++){
            if(a[i].x<a[st].x || (a[i].x==a[st].x && a[i].y<a[st].y)){
                st = i;
            }
        }

        vector<int> vis(n,0);

        vector<Point> ans;
        int p = st, q;
        ans.push_back(a[p]); 
        vis[p] = 1;
        while(1){
            q = (p+1)%n;
            for(int i=0;i<n;i++){
                if(orientation(a[p],a[q],a[i])==-1 || (orientation(a[p],a[q],a[i])==0 && (dot(a[i]-a[p],a[i]-a[p])>dot(a[q]-a[p],a[q]-a[p])))){
                    q = i;
                }
            }
            int curp = p;
            p = q;
            if(a[p]==a[st]){
                for(int i=0;i<n;i++){
                    if(!vis[i] && i!=curp && i!=q && orientation(a[curp],a[q],a[i])==0){
                        ans.push_back(a[i]);
                        vis[i] = 1;
                    }
                }
                break;
            }
            else{
                for(int i=0;i<n;i++){
                    if(!vis[i] && i!=curp && i!=q && orientation(a[curp],a[q],a[i])==0){
                        ans.push_back(a[i]);
                        vis[i] = 1;
                    }
                }
                ans.push_back(a[p]);
                vis[p] = 1;
            }
        }
        return ans;
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<Point> pt;
        for(auto v:trees){
            Point p(v[0],v[1],0);
            pt.push_back(p);
        }
        
        vector<Point> ans = convexHullJarvisMarch(pt);
        vector<vector<int>> res;
        for(auto p:ans){
            vector<int> cur;
            cur.push_back(p.x);
            cur.push_back(p.y);
            res.push_back(cur);
        }
        return res;
    }
};
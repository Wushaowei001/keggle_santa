#include <iostream>
#include "Gift.h"
#include "const.h"
#include "IOfuncs.h"

#include "NNSearcher.h"
#include "simple_solver.h"

//#include "plplot/gcw.h"
//#include "plplot/pdf.h"
//#include "plplot/plstream.h"

#include "Solution.h"
#include "SimulatedAnnealing.h"

//#include "gecodesupport.h"

using namespace std;

auto data_file = "/home/alexey/santa_data/gifts.csv";

auto sol_file = "/home/alexey/santa_data/sol.csv";
auto sol_file1 = "/home/alexey/santa_data/sol1.csv";
auto sol_file2 = "/home/alexey/santa_data/sol2.csv";
auto sol_file3 = "/home/alexey/santa_data/sol3.csv";
auto sol_file4 = "/home/alexey/santa_data/sol4.csv";


//#include "libs/gecode_examples/examples/warehouses.cpp"

int main()
{

    IOhelper io(data_file);
    auto sol = io.GenerateSolution();
    auto obj_func1 = evaluate_solution(sol.Gifts(), sol.routes);

    SimulatedAnnealing sa(sol);
    sa.work();


    /*
    vector<Gift> gifts = {
        Gift(0, 10,0,0,  10),
        Gift(1, 10,100,0, 20),
        Gift(2, 110,100,0, 30),
        Gift(3, 210,100,0, 40),
        Gift(4, 210,0,0, 100),

        Gift(5, 200,200,0, 5),
    };
    Route r(gifts);
    r.add({0,1,2,3,4});

//    auto diff1 = r.EstRemoveNode(0);
//    auto v1 = route_evaluation(gifts, r);
//    r.remove(0);
//    auto v2 = route_evaluation(gifts, r);
//    auto diff2 = v1-v2;


    auto diff1 = r.EstAddNode(4, 5);

    auto v1 = route_evaluation(gifts, r);
    r.insert(4, 5);
    auto v2 = route_evaluation(gifts, r);
    auto diff2 = v2-v1;

    auto k = diff1 - diff2;
    */


    /*
    IOhelper io(data_file);

    //auto sol = io.LoadSolution(sol_file1);
    auto sol = io.GenerateSolution();
    auto obj_func1 = evaluate_solution(sol.Gifts(), sol.routes);
    cout << fixed << obj_func1 << endl;


    RandomPointSelector move_gen(&sol);
    auto move = move_gen.RandomMove();

    Route & r = sol.routes[move.from_route_id];
    auto id_rem = r[move.from_point_pos];

    auto diff = r.EstRemoveNode(move.from_point_pos);


    auto v1 = route_evaluation(sol.gl_gift_data,r);


    r.remove(move.from_point_pos);

    auto v2 = route_evaluation(sol.gl_gift_data,r);

    auto obj_func2 = evaluate_solution(sol.Gifts(), sol.routes);

    //auto diff2 = obj_func2 - obj_func1;
    auto diff2 = v1 - v2;

    io.SaveSolution(sol, sol_file);
    */

	return 0;
}
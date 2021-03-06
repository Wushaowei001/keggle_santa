% stein9 0-1 integer program from MIPLIB 2.0 by George Nemhauser et al.,
% solving a nine item Steiner triple system
% See, e.g., http://miplib.zib.de/miplib2/miplib/stein9.mps.gz

clear;

% the (dense) 0-1 matrix with the constraints
% the first twelve constraints are of the form <sum of three variables greater equal one>
% the last constraints gives a trivial bound on the objective and is actually redundant
matrix = [
0, 1, 1, 1, 0, 0, 0, 0, 0;...
1, 0, 1, 0, 1, 0, 0, 0, 0;...
1, 1, 0, 0, 0, 1, 0, 0, 0;...
0, 0, 0, 0, 1, 1, 1, 0, 0;...
0, 0, 0, 1, 0, 1, 0, 1, 0;...
0, 0, 0, 1, 1, 0, 0, 0, 1;...
1, 0, 0, 0, 0, 0, 0, 1, 1;...
0, 1, 0, 0, 0, 0, 1, 0, 1;...
0, 0, 1, 0, 0, 0, 1, 1, 0;...
1, 0, 0, 1, 0, 0, 1, 0, 0;...
0, 1, 0, 0, 1, 0, 0, 1, 0;...
0, 0, 1, 0, 0, 1, 0, 0, 1;...
1, 1, 1, 1, 1, 1, 1, 1, 1;...
];

% all constraints are of the type a_1*x_1+...+a9*x_9 >= b
% In SCIP, constraints are represented as left hand side <= linear sum <= right hand side
% Hence, the left hand sides are all finite, the right hand sides are plus infinity
lhs = [1,1,1,1,1,1,1,1,1,1,1,1,4]';
rhs = [1e+20,1e+20,1e+20,1e+20,1e+20,1e+20,1e+20,1e+20,1e+20,1e+20,1e+20,1e+20,1e+20]';

% the variables are binary, hence, the lower bounds are zero, the upper bounds are one
lb = [0,0,0,0,0,0,0,0,0]';
ub = [1,1,1,1,1,1,1,1,1]';

% all variables are binary decision variables (you put an item into the system or not)
% the goal is to minimize the number of used variables/items
vartype = ['b','b','b','b','b','b','b','b','b'];
obj = [1,1,1,1,1,1,1,1,1]';
objsense = 'min';

% call SCIP
[bestsol, objval] = scip(matrix, lhs, rhs, obj, lb, ub, vartype, objsense);

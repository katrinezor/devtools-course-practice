// Copyright 2017 Zemlyanskiy Nikita

#ifndef MODULES_ELASTICITY_INCLUDE_DEMAND_H_
#define MODULES_ELASTICITY_INCLUDE_DEMAND_H_

enum Elasticity{Elastic, UnitElastic, NoElastic};

class Demand {
 public:
    Demand(double oldprice, double newprice,
           double olddemand, double newdemand);
    int CheckForElasticity();
    double RevenueChange(double revenue);
 protected:
    double coeffofdemand_;
    double oldprice_, newprice_;
    double olddemand_, newdemand_;
    double deltaprice_;
    double deltademand_;
    double revenue_;
    int elasticity_;
};
#endif  // MODULES_ELASTICITY_INCLUDE_DEMAND_H_

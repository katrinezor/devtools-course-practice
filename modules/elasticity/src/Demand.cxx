// Copyright 2017 Zemlyanskiy Nikita

#include "../include/Demand.h"

Demand::Demand(double oldprice, double newprice,
               double olddemand, double newdemand) {
  if ((oldprice >= 0) && (newprice >= 0) &&
     (olddemand >= 0) && (newdemand >= 0)) {
    oldprice_ = oldprice;
    olddemand_ = olddemand;
    newprice_ = newprice;
    newdemand_ = newdemand;
    if (newprice_ == oldprice_) {
      throw "Deltaprice can`t be equal zero.";
    }
    deltaprice_ = newprice - oldprice;
    deltademand_ = newdemand - olddemand;
    coeffofdemand_ = deltademand_/deltaprice_;
    revenue_ = 0;
    elasticity_ = 0;
  } else {
      throw "Price or demand can`t be < 0";
    }
}

int Demand::CheckForElasticity() {
  if (coeffofdemand_ == 1.0) {
    // Coefficient of unit elasticity
    elasticity_ = UnitElastic;
  } else if (coeffofdemand_ > 1.0) {
      // Demand is elastic
      elasticity_ = Elastic;
    } else {
        // Demand is not elastic
        elasticity_ = NoElastic;
      }
  return elasticity_;
}

double Demand::RevenueChange(double revenue_) {
  // Old revenue
  if (coeffofdemand_ >= 1.0) {
    for (int time = 0; time < 30; time++) {
    // 30 days of work
      if (newprice_ > oldprice_) {
        revenue_--;
      } else if (newprice_ < oldprice_) {
          revenue_++;
        }
    }
  }
  if (coeffofdemand_ < 1.0) {
    for (int time=0; time < 30; time++) {
      if (newprice_ > oldprice_) {
        revenue_++;
      } else if (newprice_ < oldprice_) {
          revenue_--;
        }
    }
  }
  // New revenue
  return revenue_;
}

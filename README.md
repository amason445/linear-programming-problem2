Implementation of a Linear Programming problem in C++ from: Hamdy A. Taha, Operations Research: An Introduction

Example 2.2-2 (diet Problem)
Ozark Farms uses at least 800 lb of special feed daily. The special feed is a mixture of corn and

feedstuff	 lb per lb of feedstuff
		 protein      fiber		cost ($/lp)
corn		 0.09	      0.02		0.30
soybean meal	 0.60	      0.06		0.90


The dietary requirements of the special feed are at least 30% protein and at most 5% fiber.
The goal is to determine the daily minimum-cost feed mix.
The decision variables of the model are:
x1 = lb of corn in the daily mix
x2 = lb of soybean meal in the daily mix
The objective is to minimize the total daily cost (in dollars) of the feed mix—that is,
Minimize z = .3x1 + .9x2

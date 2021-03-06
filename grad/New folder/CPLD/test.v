module test(N, WR, clk, pulse, dir, busy);

input [7:0] N;
input WR;
input clk;

output reg pulse;
output reg dir;
output reg busy;
// phan anh khai
parameter Nmax  = 250;	// chu ky dieu khien 1ms, xung 40us -> Nmax = 250

reg [7:0] Ntemp = 8'b0;
reg [8:0] acc = Nmax;

reg [8:0] clk_cnt = 0;
reg [8:0] clk_20cnt = 0;
reg clk20u = 0;
reg pre_WR = 0;

initial begin
pulse = 0;
Ntemp = 0;
clk_cnt = 0;
clk_20cnt = 0;
clk20u = 0;
pre_WR = 0;
busy = 0;
end

always @(posedge clk)  begin	
  	if ({pre_WR,WR} == 2'b00) // neu co xung WR nap gia tri moi
		begin				
			Ntemp = N[6:0];
			dir = N[7];
			clk_cnt = 0;
			clk_20cnt = 0;
			clk20u = 0;		
			acc = Nmax - 2;
			pulse = 0;
			busy = 1;
		end		
	else 
		begin
			if (clk_cnt < 399)//update every 1/20M = 50ns x 400 = 20us = chieu dai xung duong / chu ki xung
				clk_cnt = clk_cnt + 1;
			else 
				begin 
					clk_cnt = 0;
					if (clk_20cnt < 499)// 20us x 500 = 10ms
						begin 
							clk_20cnt = clk_20cnt + 1;
							clk20u = !clk20u;
							if (clk20u) 
								begin
									acc = acc + Ntemp;
									if (acc > Nmax) 
										begin
											acc = acc - Nmax;
											pulse = 1;
										end		
								end
							else 
								pulse = 0;
						end
					else
						begin
							busy  = 0;
							pulse = 0;
						end
				end
		end
	pre_WR <= WR;
end				
endmodule

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;

ENTITY case3s IS
       PORT ( table_in  : IN  STD_LOGIC_VECTOR(2 DOWNTO 0);
              table_out : OUT INTEGER RANGE -3 TO 6);
END case3s;

ARCHITECTURE LCs OF case3s IS
BEGIN

-- This is the DA CASE table for
-- the 3 coefficients: 4, -3, 2  
-- automatically generated with dagen.exe -- DO NOT EDIT!

  PROCESS (table_in)
  BEGIN
    CASE table_in IS 
      WHEN  "000" =>    table_out <=  0;
      WHEN  "001" =>    table_out <=  4;
      WHEN  "010" =>    table_out <=  -3;
      WHEN  "011" =>    table_out <=  1;
      WHEN  "100" =>    table_out <=  2;
      WHEN  "101" =>    table_out <=  6;
      WHEN  "110" =>    table_out <=  -1;
      WHEN  "111" =>    table_out <=  3;
      WHEN   OTHERS  =>    table_out <=  0;
    END CASE;
  END PROCESS;

END LCs;

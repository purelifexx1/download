var Struct = require("struct");
var realtime_data = Struct().word16Sbe('solar_voltage').word16Sbe('solar_current').word32Sle('solar_power').word16Sbe('bat_voltage').word16Sbe('bat_current').word32Sle('bat_power')
								.word16Sbe('load_vol').word16Sbe('load_current').word32Sle('load_power').word16Sbe('bat_temp').word16Sbe('temp_in').word16Sbe('bat_percent');
var statistic_data = Struct().word16Sbe('max_pv_vol_today').word16Sbe('min_pv_vol_today').word16Sbe('max_bat_vol_today').word16Sbe('min_bat_vol_today').word32Sle('con_energy_today')
								.word32Sle('con_energy_month').word32Sle('con_energy_year').word32Sle('total_con_energy').word32Sle('gen_energy_today')
								.word32Sle('gen_energy_month').word32Sle('gen_energy_year').word32Sle('total_gen_energy');
realtime_data.allocate();
statistic_data.allocate();
var realtime_union_buf = realtime_data.buffer();
var statistic_union_buf = statistic_data.buffer();
var struct_statistic_data = statistic_data.fields;
var struct_realtime_data = realtime_data.fields;

module.exports = {

	realtime_send: function(io){
		io.sockets.emit("realtime_data", struct_realtime_data);
	},
	statistic_send: function(io){
		io.sockets.emit("statistic_data", struct_statistic_data);
	}

};

module.exports.realtime_buf = realtime_union_buf;

module.exports.statistic_buf = statistic_union_buf;



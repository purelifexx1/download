var Struct = require("struct");
var realtime_data = Struct().word16Sbe('pv_vol').word16Sbe('pv_current').word32Sle('pv_power').word16Sbe('bat_vol').word16Sbe('bat_current').word32Sle('bat_power')
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
		var send_string = "";
		send_string += (struct_realtime_data.pv_vol/100).toString() + "/";
		send_string += (struct_realtime_data.pv_current/100).toString() + "/";
		send_string += (struct_realtime_data.pv_power/100).toString() + "/";
		send_string += (struct_realtime_data.bat_vol/100).toString() + "/";
		send_string += (struct_realtime_data.bat_current/100).toString() + "/";
		send_string += (struct_realtime_data.bat_power/100).toString() + "/";
		send_string += (struct_realtime_data.load_vol/100).toString() + "/";
		send_string += (struct_realtime_data.load_current/100).toString() + "/";
		send_string += (struct_realtime_data.load_power/100).toString() + "/";
		send_string += (struct_realtime_data.bat_temp/100).toString() + "/";
		send_string += (struct_realtime_data.temp_in/100).toString() + "/";
		send_string += (struct_realtime_data.bat_percent/100).toString() + "/";
		io.sockets.emit("realtime_data", send_string);
	},
	statistic_send: function(io){
		var send_string = "";
		send_string += (struct_statistic_max_px_vol_today/100).toString() + "/";
		send_string += (struct_statistic_data.min_pv_vol_today/100).toString() + "/";
		send_string += (struct_statistic_data.max_bat_vol_today/100).toString() + "/";
		send_string += (struct_statistic_data.min_bat_vol_today/100).toString() + "/";
		send_string += (struct_statistic_data.con_energy_today/100).toString() + "/";
		send_string += (struct_statistic_data.con_energy_month/100).toString() + "/";
		send_string += (struct_statistic_data.con_energy_year/100).toString() + "/";
		send_string += (struct_statistic_data.total_con_energy/100).toString() + "/";
		send_string += (struct_statistic_data.gen_energy_today/100).toString() + "/";
		send_string += (struct_statistic_data.gen_energy_month/100).toString() + "/";
		send_string += (struct_statistic_data.gen_energy_year/100).toString() + "/";
		send_string += (struct_statistic_data.total_gen_energy/100).toString() + "/";
		io.sockets.emit("statistic_data", send_string);
	}

};

module.exports.realtime_buf = realtime_union_buf;

module.exports.statistic_buf = statistic_union_buf;



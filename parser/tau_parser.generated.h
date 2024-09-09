// This file is generated from a file parser/tau.tgf by
//       https://github.com/IDNI/parser/tools/tgf
//
#ifndef __TAU_PARSER_H__
#define __TAU_PARSER_H__

#include "parser.h"

namespace tau_parser_data {

using char_type     = char;
using terminal_type = char;

inline std::vector<std::string> symbol_names{
	"", "eof", "space", "digit", "xdigit", "alpha", "alnum", "punct", "printable", "start", 
	"rr", "_", "rec_relations", "main", "wff", "__E_rec_relations_0", "rec_relation", "__E_rec_relations_1", "ref", "__E_rec_relation_2", 
	"capture", "bf", "sym", "__E_ref_3", "offsets", "ref_args", "__E_ref_args_4", "__E___E_ref_args_4_5", "ref_arg", "__E___E_ref_args_4_6", 
	"__E___E_ref_args_4_7", "inputs", "__E_inputs_8", "__E_inputs_9", "input", "in", "source_binding", "library", "rules", "__E_library_10", 
	"__E___E_library_10_11", "rule", "__E___E___E_library_10_11_12", "wff_rule", "bf_rule", "__E___E_library_10_13", "wff_matcher", "wff_body", "__E_wff_rule_14", "wff_cb", 
	"bf_matcher", "bf_body", "__E_bf_rule_15", "bf_cb", "builder", "builder_head", "builder_body", "__E_builder_head_16", "__", "__E_builder_head_17", 
	"bf_builder_body", "__E_builder_body_18", "wff_builder_body", "__E_builder_body_19", "wff_parenthesis", "__E_wff_20", "wff_sometimes", "__E_wff_21", "__E___E_wff_21_22", "wff_always", 
	"__E_wff_23", "__E___E_wff_23_24", "wff_conditional", "__E_wff_25", "wff_all", "__E_wff_26", "q_vars", "wff_ex", "__E_wff_27", "wff_ref", 
	"wff_imply", "__E_wff_28", "wff_equiv", "__E_wff_29", "wff_or", "__E_wff_30", "wff_xor", "__E_wff_31", "wff_and", "__E_wff_32", 
	"wff_neg", "__E_wff_33", "wff_t", "wff_f", "bf_interval", "__E_wff_34", "bf_neq", "__E_wff_35", "bf_eq", "__E_wff_36", 
	"bf_nleq", "__E_wff_37", "bf_greater", "__E_wff_38", "bf_less_equal", "__E_wff_39", "bf_less", "__E_wff_40", "uninterpreted_constant", "bf_parenthesis", 
	"__E_bf_41", "variable", "bf_splitter", "__E_bf_42", "bf_ref", "bf_or", "__E_bf_43", "bf_xor", "__E_bf_44", "bf_and", 
	"__E_bf_45", "__E___E_bf_45_46", "bf_neg", "__E_bf_47", "bf_constant", "__E_bf_48", "constant", "bf_t", "bf_f", "flag", 
	"flag_neq", "__E_flag_49", "flagvar", "num", "flag_eq", "__E_flag_50", "flag_greater_equal", "__E_flag_51", "flag_greater", "__E_flag_52", 
	"flag_less_equal", "__E_flag_53", "flag_less", "__E_flag_54", "charvar", "__E_charvar_55", "__E_charvar_56", "io_var", "__E_variable_57", "out", 
	"in_var_name", "__E_in_58", "digits", "offset", "out_var_name", "__E_out_59", "q_var", "__E_q_vars_60", "__E_q_vars_61", "__E_offsets_62", 
	"__E_offsets_63", "shift", "__E_offset_64", "__E_shift_65", "__E___E_shift_65_66", "uninter_const_name", "__E_uninterpreted_constant_67", "__E___E_uninterpreted_constant_67_68", "chars", "binding", 
	"__E_binding_69", "type", "__E___E_binding_69_70", "source", "named_binding", "src_c", "__E_source_71", "__E___E_source_71_72", "__E___E_source_71_73", "__E_src_c_74", 
	"__E_src_c_75", "__E_chars_76", "__E_digits_77", "extra", "comment", "__E_comment_78", "__E_comment_79", "__E_comment_80", "__E____81", "__E___82", 
	"bf_cb_args1", "bf_cb_arg", "bf_cb_args2", "bf_cb_args3", "bf_cb_args4", "wff_cb_args1", "wff_cb_arg", "wff_cb_args2", "wff_cb_args3", "wff_cb_args4", 
	"wff_has_clashing_subformulas_cb", "__E_wff_cb_83", "wff_has_subformula_cb", "__E_wff_cb_84", "wff_remove_existential_cb", "__E_wff_cb_85", "bf_has_subformula_cb", "__E_bf_cb_86", "bf_remove_funiversal_cb", "__E_bf_cb_87", 
	"bf_remove_fexistential_cb", "__E_bf_cb_88", "bf_normalize_cb", "__E_bf_cb_89", "cli", "cli_command", "__E_cli_90", "__E_cli_91", "quit_cmd", "quit_sym", 
	"__E_cli_command_92", "version_cmd", "version_sym", "__E_cli_command_93", "clear_cmd", "clear_sym", "__E_cli_command_94", "help_cmd", "__E_cli_command_95", "help_sym", 
	"__E___E_cli_command_95_96", "__E___E_cli_command_95_97", "help_arg", "file_cmd", "__E_cli_command_98", "file_sym", "q_string", "valid_cmd", "__E_cli_command_99", "valid_sym", 
	"sat_cmd", "__E_cli_command_100", "sat_sym", "unsat_cmd", "__E_cli_command_101", "unsat_sym", "solve_cmd", "__E_cli_command_102", "solve_sym", "__E___E_cli_command_102_103", 
	"solve_cmd_arg", "execute_cmd", "__E_cli_command_104", "execute_sym", "__E___E_cli_command_104_105", "__E___E_cli_command_104_106", "wff_typed", "normalize_cmd", "__E_cli_command_107", "normalize_sym", 
	"__E___E_cli_command_107_108", "normalize_cmd_arg", "subst_cmd", "__E_cli_command_109", "subst_sym", "__E___E_cli_command_109_110", "nf_cmd_arg", "inst_cmd", "__E_cli_command_111", "inst_sym", 
	"__E___E_cli_command_111_112", "inst_args", "dnf_cmd", "__E_cli_command_113", "dnf_sym", "cnf_cmd", "__E_cli_command_114", "cnf_sym", "anf_cmd", "__E_cli_command_115", 
	"anf_sym", "nnf_cmd", "__E_cli_command_116", "nnf_sym", "pnf_cmd", "__E_cli_command_117", "pnf_sym", "mnf_cmd", "__E_cli_command_118", "mnf_sym", 
	"snf_cmd", "__E_cli_command_119", "snf_sym", "onf_cmd", "__E_cli_command_120", "onf_sym", "onf_cmd_arg", "def_list_cmd", "__E_cli_command_121", "def_sym", 
	"__E___E_cli_command_121_122", "def_print_cmd", "__E_cli_command_123", "number", "def_rr_cmd", "qelim_cmd", "__E_cli_command_124", "qelim_sym", "wff_cmd_arg", "get_cmd", 
	"__E_cli_command_125", "get_sym", "__E___E_cli_command_125_126", "option", "set_cmd", "__E_cli_command_127", "set_sym", "__E___E_cli_command_127_128", "option_value", "toggle_cmd", 
	"__E_cli_command_129", "toggle_sym", "bool_option", "history_list_cmd", "__E_cli_command_130", "history_sym", "__E___E_cli_command_130_131", "history_print_cmd", "__E_cli_command_132", "memory", 
	"history_store_cmd", "__E_cli_command_133", "bf_cmd_arg", "abs_memory_sym", "rel_memory_sym", "selection_sym", "examples_sym", "__E_help_arg_134", "__E___E_help_arg_134_135", "rel_memory", 
	"__E_memory_136", "__E___E_memory_136_137", "memory_id", "abs_memory", "__E_memory_138", "enum_option", "severity_opt", "__E_option_139", "status_opt", "__E_bool_option_140", 
	"colors_opt", "__E_bool_option_141", "debug_repl_opt", "__E_bool_option_142", "option_value_true", "option_value_false", "severity", "error_sym", "__E_severity_143", "info_sym", 
	"__E_severity_144", "debug_sym", "__E_severity_145", "trace_sym", "__E_severity_146", "__N_0", "__N_1", "__N_2", "__N_3", "__N_4", 
	"__N_5", 
};

inline ::idni::nonterminals<char_type, terminal_type> nts{symbol_names};

inline std::vector<terminal_type> terminals{
	'\0', '.', ':', '=', ',', '(', ')', '<', '{', 
	'}', 's', 'o', 'm', 'e', 't', 'i', '>', 'a', 'l', 
	'w', 'y', '[', ']', '?', 'x', '-', '|', '^', '&', 
	'!', 'T', 'F', 'S', '+', '\'', '1', '0', '$', '\t', 
	'\n', '\r', '#', 'f', '_', 'h', 'c', 'n', 'g', 'u', 
	'b', 'r', 'v', 'z', 'q', 'p', 'd', '/', '%', 
};

inline ::idni::char_class_fns<terminal_type> char_classes =
	::idni::predefined_char_classes<char_type, terminal_type>({
		"eof",
		"space",
		"digit",
		"xdigit",
		"alpha",
		"alnum",
		"punct",
		"printable",
	}, nts);

inline struct ::idni::grammar<char_type, terminal_type>::options
	grammar_options
{
	.transform_negation = false,
	.auto_disambiguate = true,
	.shaping = {
		.to_trim = {
			11, 58
		},
		.trim_terminals = true,
		.dont_trim_terminals_of = {
			20, 22, 144, 150, 152, 154, 165, 171, 173, 174
		},
		.to_inline = {
			{ 14, 64, 14 },
			{ 21, 109, 21 },
			{ 49 },
			{ 53 },
			{ 156 },
			{ 168 },
			{ 175 },
			{ 190 },
			{ 192 },
			{ 193 },
			{ 194 },
			{ 195 },
			{ 197 },
			{ 198 },
			{ 199 },
			{ 250 },
			{ 261 },
			{ 266 },
			{ 271 },
			{ 296 },
			{ 308 },
			{ 332 }
		},
		.inline_char_classes = true
	}
};

inline ::idni::parser<char_type, terminal_type>::options parser_options{
};

inline ::idni::prods<char_type, terminal_type> start_symbol{ nts(9) };

inline idni::prods<char_type, terminal_type>& productions() {
	static bool loaded = false;
	static idni::prods<char_type, terminal_type>
		p, nul(idni::lit<char_type, terminal_type>{});
	if (loaded) return p;
	#define  T(x) (idni::prods<char_type, terminal_type>{ terminals[x] })
	#define NT(x) (idni::prods<char_type, terminal_type>{ nts(x) })
//G0:   start(9)             => rr(10) _(11).
	p(NT(9), (NT(10)+NT(11)));
//G1:   main(13)             => wff(14).
	p(NT(13), (NT(14)));
//G2:   rr(10)               => rec_relations(12) _(11) main(13) _(11) '.'.
	p(NT(10), (NT(12)+NT(11)+NT(13)+NT(11)+T(1)));
//G3:   __E_rec_relations_0(15) => _(11) rec_relation(16) _(11) '.'.
	p(NT(15), (NT(11)+NT(16)+NT(11)+T(1)));
//G4:   __E_rec_relations_1(17) => null.
	p(NT(17), (nul));
//G5:   __E_rec_relations_1(17) => __E_rec_relations_0(15) __E_rec_relations_1(17).
	p(NT(17), (NT(15)+NT(17)));
//G6:   rec_relations(12)    => __E_rec_relations_1(17).
	p(NT(12), (NT(17)));
//G7:   __E_rec_relation_2(19) => capture(20).
	p(NT(19), (NT(20)));
//G8:   __E_rec_relation_2(19) => ref(18).
	p(NT(19), (NT(18)));
//G9:   __E_rec_relation_2(19) => wff(14).
	p(NT(19), (NT(14)));
//G10:  __E_rec_relation_2(19) => bf(21).
	p(NT(19), (NT(21)));
//G11:  rec_relation(16)     => ref(18) _(11) ':' '=' _(11) __E_rec_relation_2(19).
	p(NT(16), (NT(18)+NT(11)+T(2)+T(3)+NT(11)+NT(19)));
//G12:  __E_ref_3(23)        => _(11) offsets(24).
	p(NT(23), (NT(11)+NT(24)));
//G13:  __E_ref_3(23)        => null.
	p(NT(23), (nul));
//G14:  ref(18)              => sym(22) __E_ref_3(23) _(11) ref_args(25).
	p(NT(18), (NT(22)+NT(23)+NT(11)+NT(25)));
//G15:  ref_arg(28)          => bf(21).
	p(NT(28), (NT(21)));
//G16:  __E___E_ref_args_4_5(27) => _(11) ref_arg(28).
	p(NT(27), (NT(11)+NT(28)));
//G17:  __E___E_ref_args_4_6(29) => _(11) ',' _(11) ref_arg(28).
	p(NT(29), (NT(11)+T(4)+NT(11)+NT(28)));
//G18:  __E___E_ref_args_4_7(30) => null.
	p(NT(30), (nul));
//G19:  __E___E_ref_args_4_7(30) => __E___E_ref_args_4_6(29) __E___E_ref_args_4_7(30).
	p(NT(30), (NT(29)+NT(30)));
//G20:  __E_ref_args_4(26)   => __E___E_ref_args_4_5(27) __E___E_ref_args_4_7(30).
	p(NT(26), (NT(27)+NT(30)));
//G21:  __E_ref_args_4(26)   => null.
	p(NT(26), (nul));
//G22:  ref_args(25)         => '(' __E_ref_args_4(26) _(11) ')'.
	p(NT(25), (T(5)+NT(26)+NT(11)+T(6)));
//G23:  __E_inputs_9(33)     => _(11) input(34).
	p(NT(33), (NT(11)+NT(34)));
//G24:  __E_inputs_8(32)     => __E_inputs_9(33).
	p(NT(32), (NT(33)));
//G25:  __E_inputs_8(32)     => __E_inputs_9(33) __E_inputs_8(32).
	p(NT(32), (NT(33)+NT(32)));
//G26:  inputs(31)           => _(11) '<' __E_inputs_8(32) _(11) '.'.
	p(NT(31), (NT(11)+T(7)+NT(32)+NT(11)+T(1)));
//G27:  input(34)            => in(35) _(11) ':' _(11) '{' _(11) source_binding(36) _(11) '}'.
	p(NT(34), (NT(35)+NT(11)+T(2)+NT(11)+T(8)+NT(11)+NT(36)+NT(11)+T(9)));
//G28:  __E___E___E_library_10_11_12(42) => wff_rule(43).
	p(NT(42), (NT(43)));
//G29:  __E___E___E_library_10_11_12(42) => bf_rule(44).
	p(NT(42), (NT(44)));
//G30:  rule(41)             => __E___E___E_library_10_11_12(42).
	p(NT(41), (NT(42)));
//G31:  __E___E_library_10_11(40) => _(11) rule(41).
	p(NT(40), (NT(11)+NT(41)));
//G32:  __E___E_library_10_13(45) => null.
	p(NT(45), (nul));
//G33:  __E___E_library_10_13(45) => __E___E_library_10_11(40) __E___E_library_10_13(45).
	p(NT(45), (NT(40)+NT(45)));
//G34:  __E_library_10(39)   => __E___E_library_10_13(45).
	p(NT(39), (NT(45)));
//G35:  rules(38)            => __E_library_10(39).
	p(NT(38), (NT(39)));
//G36:  library(37)          => rules(38).
	p(NT(37), (NT(38)));
//G37:  wff_matcher(46)      => wff(14).
	p(NT(46), (NT(14)));
//G38:  __E_wff_rule_14(48)  => wff(14).
	p(NT(48), (NT(14)));
//G39:  __E_wff_rule_14(48)  => wff_cb(49).
	p(NT(48), (NT(49)));
//G40:  wff_body(47)         => __E_wff_rule_14(48).
	p(NT(47), (NT(48)));
//G41:  wff_rule(43)         => wff_matcher(46) _(11) ':' ':' '=' _(11) wff_body(47) _(11) '.'.
	p(NT(43), (NT(46)+NT(11)+T(2)+T(2)+T(3)+NT(11)+NT(47)+NT(11)+T(1)));
//G42:  bf_matcher(50)       => bf(21).
	p(NT(50), (NT(21)));
//G43:  __E_bf_rule_15(52)   => bf(21).
	p(NT(52), (NT(21)));
//G44:  __E_bf_rule_15(52)   => bf_cb(53).
	p(NT(52), (NT(53)));
//G45:  bf_body(51)          => __E_bf_rule_15(52).
	p(NT(51), (NT(52)));
//G46:  bf_rule(44)          => bf_matcher(50) _(11) ':' '=' _(11) bf_body(51) _(11) '.'.
	p(NT(44), (NT(50)+NT(11)+T(2)+T(3)+NT(11)+NT(51)+NT(11)+T(1)));
//G47:  builder(54)          => _(11) builder_head(55) _(11) builder_body(56) _(11) '.'.
	p(NT(54), (NT(11)+NT(55)+NT(11)+NT(56)+NT(11)+T(1)));
//G48:  __E_builder_head_16(57) => __(58) capture(20).
	p(NT(57), (NT(58)+NT(20)));
//G49:  __E_builder_head_17(59) => null.
	p(NT(59), (nul));
//G50:  __E_builder_head_17(59) => __E_builder_head_16(57) __E_builder_head_17(59).
	p(NT(59), (NT(57)+NT(59)));
//G51:  builder_head(55)     => '(' _(11) capture(20) __E_builder_head_17(59) _(11) ')'.
	p(NT(55), (T(5)+NT(11)+NT(20)+NT(59)+NT(11)+T(6)));
//G52:  __E_builder_body_18(61) => '=' ':' _(11) bf(21).
	p(NT(61), (T(3)+T(2)+NT(11)+NT(21)));
//G53:  bf_builder_body(60)  => __E_builder_body_18(61).
	p(NT(60), (NT(61)));
//G54:  builder_body(56)     => bf_builder_body(60).
	p(NT(56), (NT(60)));
//G55:  __E_builder_body_19(63) => '=' ':' ':' _(11) wff(14).
	p(NT(63), (T(3)+T(2)+T(2)+NT(11)+NT(14)));
//G56:  wff_builder_body(62) => __E_builder_body_19(63).
	p(NT(62), (NT(63)));
//G57:  builder_body(56)     => wff_builder_body(62).
	p(NT(56), (NT(62)));
//G58:  __E_wff_20(65)       => '(' _(11) wff(14) _(11) ')'.
	p(NT(65), (T(5)+NT(11)+NT(14)+NT(11)+T(6)));
//G59:  wff_parenthesis(64)  => __E_wff_20(65).
	p(NT(64), (NT(65)));
//G60:  wff(14)              => wff_parenthesis(64).
	p(NT(14), (NT(64)));
//G61:  __E___E_wff_21_22(68) => 's' 'o' 'm' 'e' 't' 'i' 'm' 'e' 's'.
	p(NT(68), (T(10)+T(11)+T(12)+T(13)+T(14)+T(15)+T(12)+T(13)+T(10)));
//G62:  __E___E_wff_21_22(68) => '<' '>'.
	p(NT(68), (T(7)+T(16)));
//G63:  __E_wff_21(67)       => __E___E_wff_21_22(68) _(11) wff(14).
	p(NT(67), (NT(68)+NT(11)+NT(14)));
//G64:  wff_sometimes(66)    => __E_wff_21(67).
	p(NT(66), (NT(67)));
//G65:  wff(14)              => wff_sometimes(66).
	p(NT(14), (NT(66)));
//G66:  __E___E_wff_23_24(71) => 'a' 'l' 'w' 'a' 'y' 's'.
	p(NT(71), (T(17)+T(18)+T(19)+T(17)+T(20)+T(10)));
//G67:  __E___E_wff_23_24(71) => '[' ']'.
	p(NT(71), (T(21)+T(22)));
//G68:  __E_wff_23(70)       => __E___E_wff_23_24(71) _(11) wff(14).
	p(NT(70), (NT(71)+NT(11)+NT(14)));
//G69:  wff_always(69)       => __E_wff_23(70).
	p(NT(69), (NT(70)));
//G70:  wff(14)              => wff_always(69).
	p(NT(14), (NT(69)));
//G71:  __E_wff_25(73)       => wff(14) _(11) '?' _(11) wff(14) _(11) ':' _(11) wff(14).
	p(NT(73), (NT(14)+NT(11)+T(23)+NT(11)+NT(14)+NT(11)+T(2)+NT(11)+NT(14)));
//G72:  wff_conditional(72)  => __E_wff_25(73).
	p(NT(72), (NT(73)));
//G73:  wff(14)              => wff_conditional(72).
	p(NT(14), (NT(72)));
//G74:  __E_wff_26(75)       => 'a' 'l' 'l' __(58) q_vars(76) __(58) wff(14).
	p(NT(75), (T(17)+T(18)+T(18)+NT(58)+NT(76)+NT(58)+NT(14)));
//G75:  wff_all(74)          => __E_wff_26(75).
	p(NT(74), (NT(75)));
//G76:  wff(14)              => wff_all(74).
	p(NT(14), (NT(74)));
//G77:  __E_wff_27(78)       => 'e' 'x' __(58) q_vars(76) __(58) wff(14).
	p(NT(78), (T(13)+T(24)+NT(58)+NT(76)+NT(58)+NT(14)));
//G78:  wff_ex(77)           => __E_wff_27(78).
	p(NT(77), (NT(78)));
//G79:  wff(14)              => wff_ex(77).
	p(NT(14), (NT(77)));
//G80:  wff_ref(79)          => ref(18).
	p(NT(79), (NT(18)));
//G81:  wff(14)              => wff_ref(79).
	p(NT(14), (NT(79)));
//G82:  __E_wff_28(81)       => wff(14) _(11) '-' '>' _(11) wff(14).
	p(NT(81), (NT(14)+NT(11)+T(25)+T(16)+NT(11)+NT(14)));
//G83:  wff_imply(80)        => __E_wff_28(81).
	p(NT(80), (NT(81)));
//G84:  wff(14)              => wff_imply(80).
	p(NT(14), (NT(80)));
//G85:  __E_wff_29(83)       => wff(14) _(11) '<' '-' '>' _(11) wff(14).
	p(NT(83), (NT(14)+NT(11)+T(7)+T(25)+T(16)+NT(11)+NT(14)));
//G86:  wff_equiv(82)        => __E_wff_29(83).
	p(NT(82), (NT(83)));
//G87:  wff(14)              => wff_equiv(82).
	p(NT(14), (NT(82)));
//G88:  __E_wff_30(85)       => wff(14) _(11) '|' '|' _(11) wff(14).
	p(NT(85), (NT(14)+NT(11)+T(26)+T(26)+NT(11)+NT(14)));
//G89:  wff_or(84)           => __E_wff_30(85).
	p(NT(84), (NT(85)));
//G90:  wff(14)              => wff_or(84).
	p(NT(14), (NT(84)));
//G91:  __E_wff_31(87)       => wff(14) _(11) '^' _(11) wff(14).
	p(NT(87), (NT(14)+NT(11)+T(27)+NT(11)+NT(14)));
//G92:  wff_xor(86)          => __E_wff_31(87).
	p(NT(86), (NT(87)));
//G93:  wff(14)              => wff_xor(86).
	p(NT(14), (NT(86)));
//G94:  __E_wff_32(89)       => wff(14) _(11) '&' '&' _(11) wff(14).
	p(NT(89), (NT(14)+NT(11)+T(28)+T(28)+NT(11)+NT(14)));
//G95:  wff_and(88)          => __E_wff_32(89).
	p(NT(88), (NT(89)));
//G96:  wff(14)              => wff_and(88).
	p(NT(14), (NT(88)));
//G97:  __E_wff_33(91)       => '!' _(11) wff(14).
	p(NT(91), (T(29)+NT(11)+NT(14)));
//G98:  wff_neg(90)          => __E_wff_33(91).
	p(NT(90), (NT(91)));
//G99:  wff(14)              => wff_neg(90).
	p(NT(14), (NT(90)));
//G100: wff_t(92)            => 'T'.
	p(NT(92), (T(30)));
//G101: wff(14)              => wff_t(92).
	p(NT(14), (NT(92)));
//G102: wff_f(93)            => 'F'.
	p(NT(93), (T(31)));
//G103: wff(14)              => wff_f(93).
	p(NT(14), (NT(93)));
//G104: __E_wff_34(95)       => bf(21) _(11) '<' '=' _(11) bf(21) _(11) '<' '=' _(11) bf(21).
	p(NT(95), (NT(21)+NT(11)+T(7)+T(3)+NT(11)+NT(21)+NT(11)+T(7)+T(3)+NT(11)+NT(21)));
//G105: bf_interval(94)      => __E_wff_34(95).
	p(NT(94), (NT(95)));
//G106: wff(14)              => bf_interval(94).
	p(NT(14), (NT(94)));
//G107: __E_wff_35(97)       => bf(21) _(11) '!' '=' _(11) bf(21).
	p(NT(97), (NT(21)+NT(11)+T(29)+T(3)+NT(11)+NT(21)));
//G108: bf_neq(96)           => __E_wff_35(97).
	p(NT(96), (NT(97)));
//G109: wff(14)              => bf_neq(96).
	p(NT(14), (NT(96)));
//G110: __E_wff_36(99)       => bf(21) _(11) '=' _(11) bf(21).
	p(NT(99), (NT(21)+NT(11)+T(3)+NT(11)+NT(21)));
//G111: bf_eq(98)            => __E_wff_36(99).
	p(NT(98), (NT(99)));
//G112: wff(14)              => bf_eq(98).
	p(NT(14), (NT(98)));
//G113: __E_wff_37(101)      => bf(21) _(11) '!' '<' '=' _(11) bf(21).
	p(NT(101), (NT(21)+NT(11)+T(29)+T(7)+T(3)+NT(11)+NT(21)));
//G114: bf_nleq(100)         => __E_wff_37(101).
	p(NT(100), (NT(101)));
//G115: wff(14)              => bf_nleq(100).
	p(NT(14), (NT(100)));
//G116: __E_wff_38(103)      => bf(21) _(11) '>' _(11) bf(21).
	p(NT(103), (NT(21)+NT(11)+T(16)+NT(11)+NT(21)));
//G117: bf_greater(102)      => __E_wff_38(103).
	p(NT(102), (NT(103)));
//G118: wff(14)              => bf_greater(102).
	p(NT(14), (NT(102)));
//G119: __E_wff_39(105)      => bf(21) _(11) '<' '=' _(11) bf(21).
	p(NT(105), (NT(21)+NT(11)+T(7)+T(3)+NT(11)+NT(21)));
//G120: bf_less_equal(104)   => __E_wff_39(105).
	p(NT(104), (NT(105)));
//G121: wff(14)              => bf_less_equal(104).
	p(NT(14), (NT(104)));
//G122: __E_wff_40(107)      => bf(21) _(11) '<' _(11) bf(21).
	p(NT(107), (NT(21)+NT(11)+T(7)+NT(11)+NT(21)));
//G123: bf_less(106)         => __E_wff_40(107).
	p(NT(106), (NT(107)));
//G124: wff(14)              => bf_less(106).
	p(NT(14), (NT(106)));
//G125: wff(14)              => capture(20).
	p(NT(14), (NT(20)));
//G126: wff(14)              => uninterpreted_constant(108).
	p(NT(14), (NT(108)));
//G127: __E_bf_41(110)       => '(' _(11) bf(21) _(11) ')'.
	p(NT(110), (T(5)+NT(11)+NT(21)+NT(11)+T(6)));
//G128: bf_parenthesis(109)  => __E_bf_41(110).
	p(NT(109), (NT(110)));
//G129: bf(21)               => bf_parenthesis(109).
	p(NT(21), (NT(109)));
//G130: bf(21)               => variable(111).
	p(NT(21), (NT(111)));
//G131: __E_bf_42(113)       => 'S' _(11) '(' _(11) bf(21) _(11) ')'.
	p(NT(113), (T(32)+NT(11)+T(5)+NT(11)+NT(21)+NT(11)+T(6)));
//G132: bf_splitter(112)     => __E_bf_42(113).
	p(NT(112), (NT(113)));
//G133: bf(21)               => bf_splitter(112).
	p(NT(21), (NT(112)));
//G134: bf_ref(114)          => ref(18).
	p(NT(114), (NT(18)));
//G135: bf(21)               => bf_ref(114).
	p(NT(21), (NT(114)));
//G136: __E_bf_43(116)       => bf(21) _(11) '|' _(11) bf(21).
	p(NT(116), (NT(21)+NT(11)+T(26)+NT(11)+NT(21)));
//G137: bf_or(115)           => __E_bf_43(116).
	p(NT(115), (NT(116)));
//G138: bf(21)               => bf_or(115).
	p(NT(21), (NT(115)));
//G139: __E_bf_44(118)       => bf(21) _(11) '+' _(11) bf(21).
	p(NT(118), (NT(21)+NT(11)+T(33)+NT(11)+NT(21)));
//G140: bf_xor(117)          => __E_bf_44(118).
	p(NT(117), (NT(118)));
//G141: bf(21)               => bf_xor(117).
	p(NT(21), (NT(117)));
//G142: __E___E_bf_45_46(121) => _(11).
	p(NT(121), (NT(11)));
//G143: __E___E_bf_45_46(121) => _(11) '&' _(11).
	p(NT(121), (NT(11)+T(28)+NT(11)));
//G144: __E_bf_45(120)       => bf(21) __E___E_bf_45_46(121) bf(21).
	p(NT(120), (NT(21)+NT(121)+NT(21)));
//G145: bf_and(119)          => __E_bf_45(120).
	p(NT(119), (NT(120)));
//G146: bf(21)               => bf_and(119).
	p(NT(21), (NT(119)));
//G147: __E_bf_47(123)       => bf(21) _(11) '\''.
	p(NT(123), (NT(21)+NT(11)+T(34)));
//G148: bf_neg(122)          => __E_bf_47(123).
	p(NT(122), (NT(123)));
//G149: bf(21)               => bf_neg(122).
	p(NT(21), (NT(122)));
//G150: __E_bf_48(125)       => '{' _(11) constant(126) _(11) '}'.
	p(NT(125), (T(8)+NT(11)+NT(126)+NT(11)+T(9)));
//G151: bf_constant(124)     => __E_bf_48(125).
	p(NT(124), (NT(125)));
//G152: bf(21)               => bf_constant(124).
	p(NT(21), (NT(124)));
//G153: bf_t(127)            => '1'.
	p(NT(127), (T(35)));
//G154: bf(21)               => bf_t(127).
	p(NT(21), (NT(127)));
//G155: bf_f(128)            => '0'.
	p(NT(128), (T(36)));
//G156: bf(21)               => bf_f(128).
	p(NT(21), (NT(128)));
//G157: bf(21)               => flag(129).
	p(NT(21), (NT(129)));
//G158: bf(21)               => capture(20).
	p(NT(21), (NT(20)));
//G159: __E_flag_49(131)     => flagvar(132) _(11) '!' '=' _(11) num(133).
	p(NT(131), (NT(132)+NT(11)+T(29)+T(3)+NT(11)+NT(133)));
//G160: __E_flag_49(131)     => num(133) _(11) '!' '=' _(11) flagvar(132).
	p(NT(131), (NT(133)+NT(11)+T(29)+T(3)+NT(11)+NT(132)));
//G161: flag_neq(130)        => __E_flag_49(131).
	p(NT(130), (NT(131)));
//G162: flag(129)            => flag_neq(130).
	p(NT(129), (NT(130)));
//G163: __E_flag_50(135)     => flagvar(132) _(11) '=' _(11) num(133).
	p(NT(135), (NT(132)+NT(11)+T(3)+NT(11)+NT(133)));
//G164: __E_flag_50(135)     => num(133) _(11) '=' _(11) flagvar(132).
	p(NT(135), (NT(133)+NT(11)+T(3)+NT(11)+NT(132)));
//G165: flag_eq(134)         => __E_flag_50(135).
	p(NT(134), (NT(135)));
//G166: flag(129)            => flag_eq(134).
	p(NT(129), (NT(134)));
//G167: __E_flag_51(137)     => flagvar(132) _(11) '>' '=' _(11) num(133).
	p(NT(137), (NT(132)+NT(11)+T(16)+T(3)+NT(11)+NT(133)));
//G168: __E_flag_51(137)     => num(133) _(11) '>' '=' _(11) flagvar(132).
	p(NT(137), (NT(133)+NT(11)+T(16)+T(3)+NT(11)+NT(132)));
//G169: flag_greater_equal(136) => __E_flag_51(137).
	p(NT(136), (NT(137)));
//G170: flag(129)            => flag_greater_equal(136).
	p(NT(129), (NT(136)));
//G171: __E_flag_52(139)     => flagvar(132) _(11) '>' _(11) num(133).
	p(NT(139), (NT(132)+NT(11)+T(16)+NT(11)+NT(133)));
//G172: __E_flag_52(139)     => num(133) _(11) '>' _(11) flagvar(132).
	p(NT(139), (NT(133)+NT(11)+T(16)+NT(11)+NT(132)));
//G173: flag_greater(138)    => __E_flag_52(139).
	p(NT(138), (NT(139)));
//G174: flag(129)            => flag_greater(138).
	p(NT(129), (NT(138)));
//G175: __E_flag_53(141)     => flagvar(132) _(11) '<' '=' _(11) num(133).
	p(NT(141), (NT(132)+NT(11)+T(7)+T(3)+NT(11)+NT(133)));
//G176: __E_flag_53(141)     => num(133) _(11) '<' '=' _(11) flagvar(132).
	p(NT(141), (NT(133)+NT(11)+T(7)+T(3)+NT(11)+NT(132)));
//G177: flag_less_equal(140) => __E_flag_53(141).
	p(NT(140), (NT(141)));
//G178: flag(129)            => flag_less_equal(140).
	p(NT(129), (NT(140)));
//G179: __E_flag_54(143)     => flagvar(132) _(11) '<' _(11) num(133).
	p(NT(143), (NT(132)+NT(11)+T(7)+NT(11)+NT(133)));
//G180: __E_flag_54(143)     => num(133) _(11) '<' _(11) flagvar(132).
	p(NT(143), (NT(133)+NT(11)+T(7)+NT(11)+NT(132)));
//G181: flag_less(142)       => __E_flag_54(143).
	p(NT(142), (NT(143)));
//G182: flag(129)            => flag_less(142).
	p(NT(129), (NT(142)));
//G183: __N_0(365)           => 'F'.
	p(NT(365), (T(31)));
//G184: __N_1(366)           => 'T'.
	p(NT(366), (T(30)));
//G185: __E_charvar_55(145)  => ~( __N_0(365) ) & ~( __N_1(366) ) & alpha(5).	 # conjunctive
	p(NT(145), ~(NT(365)) & ~(NT(366)) & (NT(5)));
//G186: __E_charvar_56(146)  => null.
	p(NT(146), (nul));
//G187: __E_charvar_56(146)  => digit(3) __E_charvar_56(146).
	p(NT(146), (NT(3)+NT(146)));
//G188: charvar(144)         => __E_charvar_55(145) __E_charvar_56(146).
	p(NT(144), (NT(145)+NT(146)));
//G189: flagvar(132)         => charvar(144).
	p(NT(132), (NT(144)));
//G190: variable(111)        => charvar(144).
	p(NT(111), (NT(144)));
//G191: __E_variable_57(148) => in(35).
	p(NT(148), (NT(35)));
//G192: __E_variable_57(148) => out(149).
	p(NT(148), (NT(149)));
//G193: io_var(147)          => __E_variable_57(148).
	p(NT(147), (NT(148)));
//G194: variable(111)        => io_var(147).
	p(NT(111), (NT(147)));
//G195: __E_in_58(151)       => 'i' digits(152).
	p(NT(151), (T(15)+NT(152)));
//G196: in_var_name(150)     => __E_in_58(151).
	p(NT(150), (NT(151)));
//G197: in(35)               => in_var_name(150) '[' offset(153) ']'.
	p(NT(35), (NT(150)+T(21)+NT(153)+T(22)));
//G198: __E_out_59(155)      => 'o' digits(152).
	p(NT(155), (T(11)+NT(152)));
//G199: out_var_name(154)    => __E_out_59(155).
	p(NT(154), (NT(155)));
//G200: out(149)             => out_var_name(154) '[' offset(153) ']'.
	p(NT(149), (NT(154)+T(21)+NT(153)+T(22)));
//G201: capture(20)          => '$' charvar(144).
	p(NT(20), (T(37)+NT(144)));
//G202: __E_q_vars_60(157)   => _(11) ',' _(11) q_var(156).
	p(NT(157), (NT(11)+T(4)+NT(11)+NT(156)));
//G203: __E_q_vars_61(158)   => null.
	p(NT(158), (nul));
//G204: __E_q_vars_61(158)   => __E_q_vars_60(157) __E_q_vars_61(158).
	p(NT(158), (NT(157)+NT(158)));
//G205: q_vars(76)           => q_var(156) __E_q_vars_61(158).
	p(NT(76), (NT(156)+NT(158)));
//G206: q_var(156)           => capture(20).
	p(NT(156), (NT(20)));
//G207: q_var(156)           => variable(111).
	p(NT(156), (NT(111)));
//G208: __E_offsets_62(159)  => _(11) ',' _(11) offset(153).
	p(NT(159), (NT(11)+T(4)+NT(11)+NT(153)));
//G209: __E_offsets_63(160)  => null.
	p(NT(160), (nul));
//G210: __E_offsets_63(160)  => __E_offsets_62(159) __E_offsets_63(160).
	p(NT(160), (NT(159)+NT(160)));
//G211: offsets(24)          => '[' _(11) offset(153) __E_offsets_63(160) _(11) ']'.
	p(NT(24), (T(21)+NT(11)+NT(153)+NT(160)+NT(11)+T(22)));
//G212: offset(153)          => num(133).
	p(NT(153), (NT(133)));
//G213: offset(153)          => capture(20).
	p(NT(153), (NT(20)));
//G214: offset(153)          => shift(161).
	p(NT(153), (NT(161)));
//G215: __N_2(367)           => io_var(147).
	p(NT(367), (NT(147)));
//G216: __E_offset_64(162)   => variable(111) & ~( __N_2(367) ).	 # conjunctive
	p(NT(162), (NT(111)) & ~(NT(367)));
//G217: offset(153)          => __E_offset_64(162).
	p(NT(153), (NT(162)));
//G218: __E_shift_65(163)    => capture(20).
	p(NT(163), (NT(20)));
//G219: __N_3(368)           => io_var(147).
	p(NT(368), (NT(147)));
//G220: __E___E_shift_65_66(164) => variable(111) & ~( __N_3(368) ).	 # conjunctive
	p(NT(164), (NT(111)) & ~(NT(368)));
//G221: __E_shift_65(163)    => __E___E_shift_65_66(164).
	p(NT(163), (NT(164)));
//G222: shift(161)           => __E_shift_65(163) _(11) '-' _(11) num(133).
	p(NT(161), (NT(163)+NT(11)+T(25)+NT(11)+NT(133)));
//G223: num(133)             => digits(152).
	p(NT(133), (NT(152)));
//G224: __E___E_uninterpreted_constant_67_68(167) => chars(168).
	p(NT(167), (NT(168)));
//G225: __E___E_uninterpreted_constant_67_68(167) => _(11).
	p(NT(167), (NT(11)));
//G226: __E_uninterpreted_constant_67(166) => __E___E_uninterpreted_constant_67_68(167) ':' chars(168).
	p(NT(166), (NT(167)+T(2)+NT(168)));
//G227: uninter_const_name(165) => __E_uninterpreted_constant_67(166).
	p(NT(165), (NT(166)));
//G228: uninterpreted_constant(108) => '<' uninter_const_name(165) _(11) '>'.
	p(NT(108), (T(7)+NT(165)+NT(11)+T(16)));
//G229: constant(126)        => binding(169).
	p(NT(126), (NT(169)));
//G230: constant(126)        => capture(20).
	p(NT(126), (NT(20)));
//G231: __E___E_binding_69_70(172) => chars(168) _(11).
	p(NT(172), (NT(168)+NT(11)));
//G232: __E___E_binding_69_70(172) => _(11).
	p(NT(172), (NT(11)));
//G233: type(171)            => __E___E_binding_69_70(172).
	p(NT(171), (NT(172)));
//G234: __E_binding_69(170)  => type(171) ':' _(11) source(173).
	p(NT(170), (NT(171)+T(2)+NT(11)+NT(173)));
//G235: source_binding(36)   => __E_binding_69(170).
	p(NT(36), (NT(170)));
//G236: binding(169)         => source_binding(36).
	p(NT(169), (NT(36)));
//G237: named_binding(174)   => chars(168).
	p(NT(174), (NT(168)));
//G238: binding(169)         => named_binding(174).
	p(NT(169), (NT(174)));
//G239: __E___E_source_71_72(177) => src_c(175).
	p(NT(177), (NT(175)));
//G240: __E___E_source_71_72(177) => space(2).
	p(NT(177), (NT(2)));
//G241: __E___E_source_71_73(178) => null.
	p(NT(178), (nul));
//G242: __E___E_source_71_73(178) => __E___E_source_71_72(177) __E___E_source_71_73(178).
	p(NT(178), (NT(177)+NT(178)));
//G243: __E_source_71(176)   => __E___E_source_71_73(178) src_c(175).
	p(NT(176), (NT(178)+NT(175)));
//G244: __E_source_71(176)   => null.
	p(NT(176), (nul));
//G245: source(173)          => src_c(175) __E_source_71(176).
	p(NT(173), (NT(175)+NT(176)));
//G246: src_c(175)           => alnum(6).
	p(NT(175), (NT(6)));
//G247: __N_4(369)           => '{'.
	p(NT(369), (T(8)));
//G248: __N_5(370)           => '}'.
	p(NT(370), (T(9)));
//G249: src_c(175)           => ~( __N_4(369) ) & ~( __N_5(370) ) & punct(7).	 # conjunctive
	p(NT(175), ~(NT(369)) & ~(NT(370)) & (NT(7)));
//G250: __E_src_c_74(179)    => src_c(175).
	p(NT(179), (NT(175)));
//G251: __E_src_c_74(179)    => space(2).
	p(NT(179), (NT(2)));
//G252: __E_src_c_75(180)    => null.
	p(NT(180), (nul));
//G253: __E_src_c_75(180)    => __E_src_c_74(179) __E_src_c_75(180).
	p(NT(180), (NT(179)+NT(180)));
//G254: src_c(175)           => '{' __E_src_c_75(180) '}'.
	p(NT(175), (T(8)+NT(180)+T(9)));
//G255: __E_chars_76(181)    => null.
	p(NT(181), (nul));
//G256: __E_chars_76(181)    => alnum(6) __E_chars_76(181).
	p(NT(181), (NT(6)+NT(181)));
//G257: chars(168)           => alpha(5) __E_chars_76(181).
	p(NT(168), (NT(5)+NT(181)));
//G258: __E_digits_77(182)   => digit(3).
	p(NT(182), (NT(3)));
//G259: __E_digits_77(182)   => digit(3) __E_digits_77(182).
	p(NT(182), (NT(3)+NT(182)));
//G260: digits(152)          => __E_digits_77(182).
	p(NT(152), (NT(182)));
//G261: sym(22)              => chars(168).
	p(NT(22), (NT(168)));
//G262: extra(183)           => chars(168).
	p(NT(183), (NT(168)));
//G263: __E_comment_78(185)  => printable(8).
	p(NT(185), (NT(8)));
//G264: __E_comment_78(185)  => '\t'.
	p(NT(185), (T(38)));
//G265: __E_comment_79(186)  => null.
	p(NT(186), (nul));
//G266: __E_comment_79(186)  => __E_comment_78(185) __E_comment_79(186).
	p(NT(186), (NT(185)+NT(186)));
//G267: __E_comment_80(187)  => '\n'.
	p(NT(187), (T(39)));
//G268: __E_comment_80(187)  => '\r'.
	p(NT(187), (T(40)));
//G269: __E_comment_80(187)  => eof(1).
	p(NT(187), (NT(1)));
//G270: comment(184)         => '#' __E_comment_79(186) __E_comment_80(187).
	p(NT(184), (T(41)+NT(186)+NT(187)));
//G271: __E____81(188)       => space(2).
	p(NT(188), (NT(2)));
//G272: __E____81(188)       => comment(184).
	p(NT(188), (NT(184)));
//G273: __(58)               => __E____81(188) _(11).
	p(NT(58), (NT(188)+NT(11)));
//G274: __E___82(189)        => __(58).
	p(NT(189), (NT(58)));
//G275: __E___82(189)        => null.
	p(NT(189), (nul));
//G276: _(11)                => __E___82(189).
	p(NT(11), (NT(189)));
//G277: bf_cb_arg(191)       => bf(21).
	p(NT(191), (NT(21)));
//G278: bf_cb_args1(190)     => __(58) bf_cb_arg(191).
	p(NT(190), (NT(58)+NT(191)));
//G279: bf_cb_args2(192)     => bf_cb_args1(190) bf_cb_args1(190).
	p(NT(192), (NT(190)+NT(190)));
//G280: bf_cb_args3(193)     => bf_cb_args2(192) bf_cb_args1(190).
	p(NT(193), (NT(192)+NT(190)));
//G281: bf_cb_args4(194)     => bf_cb_args3(193) bf_cb_args1(190).
	p(NT(194), (NT(193)+NT(190)));
//G282: wff_cb_arg(196)      => wff(14).
	p(NT(196), (NT(14)));
//G283: wff_cb_args1(195)    => __(58) wff_cb_arg(196).
	p(NT(195), (NT(58)+NT(196)));
//G284: wff_cb_args2(197)    => wff_cb_args1(195) wff_cb_args1(195).
	p(NT(197), (NT(195)+NT(195)));
//G285: wff_cb_args3(198)    => wff_cb_args2(197) wff_cb_args1(195).
	p(NT(198), (NT(197)+NT(195)));
//G286: wff_cb_args4(199)    => wff_cb_args3(198) wff_cb_args1(195).
	p(NT(199), (NT(198)+NT(195)));
//G287: __E_wff_cb_83(201)   => 'w' 'f' 'f' '_' 'h' 'a' 's' '_' 'c' 'l' 'a' 's' 'h' 'i' 'n' 'g' '_' 's' 'u' 'b' 'f' 'o' 'r' 'm' 'u' 'l' 'a' 's' '_' 'c' 'b' wff_cb_args2(197).
	p(NT(201), (T(19)+T(42)+T(42)+T(43)+T(44)+T(17)+T(10)+T(43)+T(45)+T(18)+T(17)+T(10)+T(44)+T(15)+T(46)+T(47)+T(43)+T(10)+T(48)+T(49)+T(42)+T(11)+T(50)+T(12)+T(48)+T(18)+T(17)+T(10)+T(43)+T(45)+T(49)+NT(197)));
//G288: wff_has_clashing_subformulas_cb(200) => __E_wff_cb_83(201).
	p(NT(200), (NT(201)));
//G289: wff_cb(49)           => wff_has_clashing_subformulas_cb(200).
	p(NT(49), (NT(200)));
//G290: __E_wff_cb_84(203)   => 'w' 'f' 'f' '_' 'h' 'a' 's' '_' 's' 'u' 'b' 'f' 'o' 'r' 'm' 'u' 'l' 'a' '_' 'c' 'b' wff_cb_args3(198).
	p(NT(203), (T(19)+T(42)+T(42)+T(43)+T(44)+T(17)+T(10)+T(43)+T(10)+T(48)+T(49)+T(42)+T(11)+T(50)+T(12)+T(48)+T(18)+T(17)+T(43)+T(45)+T(49)+NT(198)));
//G291: wff_has_subformula_cb(202) => __E_wff_cb_84(203).
	p(NT(202), (NT(203)));
//G292: wff_cb(49)           => wff_has_subformula_cb(202).
	p(NT(49), (NT(202)));
//G293: __E_wff_cb_85(205)   => 'w' 'f' 'f' '_' 'r' 'e' 'm' 'o' 'v' 'e' '_' 'e' 'x' 'i' 's' 't' 'e' 'n' 't' 'i' 'a' 'l' '_' 'c' 'b' wff_cb_args2(197).
	p(NT(205), (T(19)+T(42)+T(42)+T(43)+T(50)+T(13)+T(12)+T(11)+T(51)+T(13)+T(43)+T(13)+T(24)+T(15)+T(10)+T(14)+T(13)+T(46)+T(14)+T(15)+T(17)+T(18)+T(43)+T(45)+T(49)+NT(197)));
//G294: wff_remove_existential_cb(204) => __E_wff_cb_85(205).
	p(NT(204), (NT(205)));
//G295: wff_cb(49)           => wff_remove_existential_cb(204).
	p(NT(49), (NT(204)));
//G296: __E_bf_cb_86(207)    => 'b' 'f' '_' 'h' 'a' 's' '_' 's' 'u' 'b' 'f' 'o' 'r' 'm' 'u' 'l' 'a' '_' 'c' 'b' bf_cb_args3(193).
	p(NT(207), (T(49)+T(42)+T(43)+T(44)+T(17)+T(10)+T(43)+T(10)+T(48)+T(49)+T(42)+T(11)+T(50)+T(12)+T(48)+T(18)+T(17)+T(43)+T(45)+T(49)+NT(193)));
//G297: bf_has_subformula_cb(206) => __E_bf_cb_86(207).
	p(NT(206), (NT(207)));
//G298: bf_cb(53)            => bf_has_subformula_cb(206).
	p(NT(53), (NT(206)));
//G299: __E_bf_cb_87(209)    => 'b' 'f' '_' 'r' 'e' 'm' 'o' 'v' 'e' '_' 'f' 'u' 'n' 'i' 'v' 'e' 'r' 's' 'a' 'l' '_' 'c' 'b' bf_cb_args4(194).
	p(NT(209), (T(49)+T(42)+T(43)+T(50)+T(13)+T(12)+T(11)+T(51)+T(13)+T(43)+T(42)+T(48)+T(46)+T(15)+T(51)+T(13)+T(50)+T(10)+T(17)+T(18)+T(43)+T(45)+T(49)+NT(194)));
//G300: bf_remove_funiversal_cb(208) => __E_bf_cb_87(209).
	p(NT(208), (NT(209)));
//G301: bf_cb(53)            => bf_remove_funiversal_cb(208).
	p(NT(53), (NT(208)));
//G302: __E_bf_cb_88(211)    => 'b' 'f' '_' 'r' 'e' 'm' 'o' 'v' 'e' '_' 'f' 'e' 'x' 'i' 's' 't' 'e' 'n' 't' 'i' 'a' 'l' '_' 'c' 'b' bf_cb_args4(194).
	p(NT(211), (T(49)+T(42)+T(43)+T(50)+T(13)+T(12)+T(11)+T(51)+T(13)+T(43)+T(42)+T(13)+T(24)+T(15)+T(10)+T(14)+T(13)+T(46)+T(14)+T(15)+T(17)+T(18)+T(43)+T(45)+T(49)+NT(194)));
//G303: bf_remove_fexistential_cb(210) => __E_bf_cb_88(211).
	p(NT(210), (NT(211)));
//G304: bf_cb(53)            => bf_remove_fexistential_cb(210).
	p(NT(53), (NT(210)));
//G305: __E_bf_cb_89(213)    => 'b' 'f' '_' 'n' 'o' 'r' 'm' 'a' 'l' 'i' 'z' 'e' '_' 'c' 'b' bf_cb_args1(190).
	p(NT(213), (T(49)+T(42)+T(43)+T(46)+T(11)+T(50)+T(12)+T(17)+T(18)+T(15)+T(52)+T(13)+T(43)+T(45)+T(49)+NT(190)));
//G306: bf_normalize_cb(212) => __E_bf_cb_89(213).
	p(NT(212), (NT(213)));
//G307: bf_cb(53)            => bf_normalize_cb(212).
	p(NT(53), (NT(212)));
//G308: cli(214)             => _(11).
	p(NT(214), (NT(11)));
//G309: __E_cli_90(216)      => '.' _(11) cli_command(215) _(11).
	p(NT(216), (T(1)+NT(11)+NT(215)+NT(11)));
//G310: __E_cli_91(217)      => null.
	p(NT(217), (nul));
//G311: __E_cli_91(217)      => __E_cli_90(216) __E_cli_91(217).
	p(NT(217), (NT(216)+NT(217)));
//G312: cli(214)             => _(11) cli_command(215) _(11) __E_cli_91(217).
	p(NT(214), (NT(11)+NT(215)+NT(11)+NT(217)));
//G313: __E_cli_command_92(220) => 'q'.
	p(NT(220), (T(53)));
//G314: __E_cli_command_92(220) => 'q' 'u' 'i' 't'.
	p(NT(220), (T(53)+T(48)+T(15)+T(14)));
//G315: quit_sym(219)        => __E_cli_command_92(220).
	p(NT(219), (NT(220)));
//G316: quit_cmd(218)        => quit_sym(219).
	p(NT(218), (NT(219)));
//G317: cli_command(215)     => quit_cmd(218).
	p(NT(215), (NT(218)));
//G318: __E_cli_command_93(223) => 'v'.
	p(NT(223), (T(51)));
//G319: __E_cli_command_93(223) => 'v' 'e' 'r' 's' 'i' 'o' 'n'.
	p(NT(223), (T(51)+T(13)+T(50)+T(10)+T(15)+T(11)+T(46)));
//G320: version_sym(222)     => __E_cli_command_93(223).
	p(NT(222), (NT(223)));
//G321: version_cmd(221)     => version_sym(222).
	p(NT(221), (NT(222)));
//G322: cli_command(215)     => version_cmd(221).
	p(NT(215), (NT(221)));
//G323: __E_cli_command_94(226) => 'c'.
	p(NT(226), (T(45)));
//G324: __E_cli_command_94(226) => 'c' 'l' 'e' 'a' 'r'.
	p(NT(226), (T(45)+T(18)+T(13)+T(17)+T(50)));
//G325: clear_sym(225)       => __E_cli_command_94(226).
	p(NT(225), (NT(226)));
//G326: clear_cmd(224)       => clear_sym(225).
	p(NT(224), (NT(225)));
//G327: cli_command(215)     => clear_cmd(224).
	p(NT(215), (NT(224)));
//G328: __E___E_cli_command_95_96(230) => 'h'.
	p(NT(230), (T(44)));
//G329: __E___E_cli_command_95_96(230) => 'h' 'e' 'l' 'p'.
	p(NT(230), (T(44)+T(13)+T(18)+T(54)));
//G330: help_sym(229)        => __E___E_cli_command_95_96(230).
	p(NT(229), (NT(230)));
//G331: __E___E_cli_command_95_97(231) => __(58) help_arg(232).
	p(NT(231), (NT(58)+NT(232)));
//G332: __E___E_cli_command_95_97(231) => null.
	p(NT(231), (nul));
//G333: __E_cli_command_95(228) => help_sym(229) __E___E_cli_command_95_97(231).
	p(NT(228), (NT(229)+NT(231)));
//G334: help_cmd(227)        => __E_cli_command_95(228).
	p(NT(227), (NT(228)));
//G335: cli_command(215)     => help_cmd(227).
	p(NT(215), (NT(227)));
//G336: file_sym(235)        => 'f' 'i' 'l' 'e'.
	p(NT(235), (T(42)+T(15)+T(18)+T(13)));
//G337: __E_cli_command_98(234) => file_sym(235) __(58) q_string(236).
	p(NT(234), (NT(235)+NT(58)+NT(236)));
//G338: file_cmd(233)        => __E_cli_command_98(234).
	p(NT(233), (NT(234)));
//G339: cli_command(215)     => file_cmd(233).
	p(NT(215), (NT(233)));
//G340: valid_sym(239)       => 'v' 'a' 'l' 'i' 'd'.
	p(NT(239), (T(51)+T(17)+T(18)+T(15)+T(55)));
//G341: __E_cli_command_99(238) => valid_sym(239) __(58) rr(10).
	p(NT(238), (NT(239)+NT(58)+NT(10)));
//G342: valid_cmd(237)       => __E_cli_command_99(238).
	p(NT(237), (NT(238)));
//G343: cli_command(215)     => valid_cmd(237).
	p(NT(215), (NT(237)));
//G344: sat_sym(242)         => 's' 'a' 't'.
	p(NT(242), (T(10)+T(17)+T(14)));
//G345: __E_cli_command_100(241) => sat_sym(242) __(58) rr(10).
	p(NT(241), (NT(242)+NT(58)+NT(10)));
//G346: sat_cmd(240)         => __E_cli_command_100(241).
	p(NT(240), (NT(241)));
//G347: cli_command(215)     => sat_cmd(240).
	p(NT(215), (NT(240)));
//G348: unsat_sym(245)       => 'u' 'n' 's' 'a' 't'.
	p(NT(245), (T(48)+T(46)+T(10)+T(17)+T(14)));
//G349: __E_cli_command_101(244) => unsat_sym(245) __(58) rr(10).
	p(NT(244), (NT(245)+NT(58)+NT(10)));
//G350: unsat_cmd(243)       => __E_cli_command_101(244).
	p(NT(243), (NT(244)));
//G351: cli_command(215)     => unsat_cmd(243).
	p(NT(215), (NT(243)));
//G352: solve_sym(248)       => 's' 'o' 'l' 'v' 'e'.
	p(NT(248), (T(10)+T(11)+T(18)+T(51)+T(13)));
//G353: __E___E_cli_command_102_103(249) => __(58) type(171).
	p(NT(249), (NT(58)+NT(171)));
//G354: __E___E_cli_command_102_103(249) => null.
	p(NT(249), (nul));
//G355: __E_cli_command_102(247) => solve_sym(248) __E___E_cli_command_102_103(249) __(58) solve_cmd_arg(250).
	p(NT(247), (NT(248)+NT(249)+NT(58)+NT(250)));
//G356: solve_cmd(246)       => __E_cli_command_102(247).
	p(NT(246), (NT(247)));
//G357: cli_command(215)     => solve_cmd(246).
	p(NT(215), (NT(246)));
//G358: __E___E_cli_command_104_105(254) => 'e'.
	p(NT(254), (T(13)));
//G359: __E___E_cli_command_104_105(254) => 'e' 'x' 'e' 'c' 'u' 't' 'e'.
	p(NT(254), (T(13)+T(24)+T(13)+T(45)+T(48)+T(14)+T(13)));
//G360: execute_sym(253)     => __E___E_cli_command_104_105(254).
	p(NT(253), (NT(254)));
//G361: __E___E_cli_command_104_106(255) => wff_typed(256).
	p(NT(255), (NT(256)));
//G362: __E___E_cli_command_104_106(255) => rr(10).
	p(NT(255), (NT(10)));
//G363: __E_cli_command_104(252) => execute_sym(253) __(58) __E___E_cli_command_104_106(255).
	p(NT(252), (NT(253)+NT(58)+NT(255)));
//G364: execute_cmd(251)     => __E_cli_command_104(252).
	p(NT(251), (NT(252)));
//G365: cli_command(215)     => execute_cmd(251).
	p(NT(215), (NT(251)));
//G366: __E___E_cli_command_107_108(260) => 'n'.
	p(NT(260), (T(46)));
//G367: __E___E_cli_command_107_108(260) => 'n' 'o' 'r' 'm' 'a' 'l' 'i' 'z' 'e'.
	p(NT(260), (T(46)+T(11)+T(50)+T(12)+T(17)+T(18)+T(15)+T(52)+T(13)));
//G368: normalize_sym(259)   => __E___E_cli_command_107_108(260).
	p(NT(259), (NT(260)));
//G369: __E_cli_command_107(258) => normalize_sym(259) __(58) normalize_cmd_arg(261).
	p(NT(258), (NT(259)+NT(58)+NT(261)));
//G370: normalize_cmd(257)   => __E_cli_command_107(258).
	p(NT(257), (NT(258)));
//G371: cli_command(215)     => normalize_cmd(257).
	p(NT(215), (NT(257)));
//G372: __E___E_cli_command_109_110(265) => 's'.
	p(NT(265), (T(10)));
//G373: __E___E_cli_command_109_110(265) => 's' 'u' 'b' 's' 't'.
	p(NT(265), (T(10)+T(48)+T(49)+T(10)+T(14)));
//G374: __E___E_cli_command_109_110(265) => 's' 'u' 'b' 's' 't' 'i' 't' 'u' 't' 'e'.
	p(NT(265), (T(10)+T(48)+T(49)+T(10)+T(14)+T(15)+T(14)+T(48)+T(14)+T(13)));
//G375: subst_sym(264)       => __E___E_cli_command_109_110(265).
	p(NT(264), (NT(265)));
//G376: __E_cli_command_109(263) => subst_sym(264) __(58) nf_cmd_arg(266) _(11) '[' _(11) nf_cmd_arg(266) _(11) '/' _(11) nf_cmd_arg(266) _(11) ']'.
	p(NT(263), (NT(264)+NT(58)+NT(266)+NT(11)+T(21)+NT(11)+NT(266)+NT(11)+T(56)+NT(11)+NT(266)+NT(11)+T(22)));
//G377: subst_cmd(262)       => __E_cli_command_109(263).
	p(NT(262), (NT(263)));
//G378: cli_command(215)     => subst_cmd(262).
	p(NT(215), (NT(262)));
//G379: __E___E_cli_command_111_112(270) => 'i'.
	p(NT(270), (T(15)));
//G380: __E___E_cli_command_111_112(270) => 'i' 'n' 's' 't'.
	p(NT(270), (T(15)+T(46)+T(10)+T(14)));
//G381: __E___E_cli_command_111_112(270) => 'i' 'n' 's' 't' 'a' 'n' 't' 'i' 'a' 't' 'e'.
	p(NT(270), (T(15)+T(46)+T(10)+T(14)+T(17)+T(46)+T(14)+T(15)+T(17)+T(14)+T(13)));
//G382: inst_sym(269)        => __E___E_cli_command_111_112(270).
	p(NT(269), (NT(270)));
//G383: __E_cli_command_111(268) => inst_sym(269) __(58) inst_args(271).
	p(NT(268), (NT(269)+NT(58)+NT(271)));
//G384: inst_cmd(267)        => __E_cli_command_111(268).
	p(NT(267), (NT(268)));
//G385: cli_command(215)     => inst_cmd(267).
	p(NT(215), (NT(267)));
//G386: dnf_sym(274)         => 'd' 'n' 'f'.
	p(NT(274), (T(55)+T(46)+T(42)));
//G387: __E_cli_command_113(273) => dnf_sym(274) __(58) nf_cmd_arg(266).
	p(NT(273), (NT(274)+NT(58)+NT(266)));
//G388: dnf_cmd(272)         => __E_cli_command_113(273).
	p(NT(272), (NT(273)));
//G389: cli_command(215)     => dnf_cmd(272).
	p(NT(215), (NT(272)));
//G390: cnf_sym(277)         => 'c' 'n' 'f'.
	p(NT(277), (T(45)+T(46)+T(42)));
//G391: __E_cli_command_114(276) => cnf_sym(277) __(58) nf_cmd_arg(266).
	p(NT(276), (NT(277)+NT(58)+NT(266)));
//G392: cnf_cmd(275)         => __E_cli_command_114(276).
	p(NT(275), (NT(276)));
//G393: cli_command(215)     => cnf_cmd(275).
	p(NT(215), (NT(275)));
//G394: anf_sym(280)         => 'a' 'n' 'f'.
	p(NT(280), (T(17)+T(46)+T(42)));
//G395: __E_cli_command_115(279) => anf_sym(280) __(58) nf_cmd_arg(266).
	p(NT(279), (NT(280)+NT(58)+NT(266)));
//G396: anf_cmd(278)         => __E_cli_command_115(279).
	p(NT(278), (NT(279)));
//G397: cli_command(215)     => anf_cmd(278).
	p(NT(215), (NT(278)));
//G398: nnf_sym(283)         => 'n' 'n' 'f'.
	p(NT(283), (T(46)+T(46)+T(42)));
//G399: __E_cli_command_116(282) => nnf_sym(283) __(58) nf_cmd_arg(266).
	p(NT(282), (NT(283)+NT(58)+NT(266)));
//G400: nnf_cmd(281)         => __E_cli_command_116(282).
	p(NT(281), (NT(282)));
//G401: cli_command(215)     => nnf_cmd(281).
	p(NT(215), (NT(281)));
//G402: pnf_sym(286)         => 'p' 'n' 'f'.
	p(NT(286), (T(54)+T(46)+T(42)));
//G403: __E_cli_command_117(285) => pnf_sym(286) __(58) nf_cmd_arg(266).
	p(NT(285), (NT(286)+NT(58)+NT(266)));
//G404: pnf_cmd(284)         => __E_cli_command_117(285).
	p(NT(284), (NT(285)));
//G405: cli_command(215)     => pnf_cmd(284).
	p(NT(215), (NT(284)));
//G406: mnf_sym(289)         => 'm' 'n' 'f'.
	p(NT(289), (T(12)+T(46)+T(42)));
//G407: __E_cli_command_118(288) => mnf_sym(289) __(58) nf_cmd_arg(266).
	p(NT(288), (NT(289)+NT(58)+NT(266)));
//G408: mnf_cmd(287)         => __E_cli_command_118(288).
	p(NT(287), (NT(288)));
//G409: cli_command(215)     => mnf_cmd(287).
	p(NT(215), (NT(287)));
//G410: snf_sym(292)         => 's' 'n' 'f'.
	p(NT(292), (T(10)+T(46)+T(42)));
//G411: __E_cli_command_119(291) => snf_sym(292) __(58) nf_cmd_arg(266).
	p(NT(291), (NT(292)+NT(58)+NT(266)));
//G412: snf_cmd(290)         => __E_cli_command_119(291).
	p(NT(290), (NT(291)));
//G413: cli_command(215)     => snf_cmd(290).
	p(NT(215), (NT(290)));
//G414: onf_sym(295)         => 'o' 'n' 'f'.
	p(NT(295), (T(11)+T(46)+T(42)));
//G415: __E_cli_command_120(294) => onf_sym(295) __(58) variable(111) __(58) onf_cmd_arg(296).
	p(NT(294), (NT(295)+NT(58)+NT(111)+NT(58)+NT(296)));
//G416: onf_cmd(293)         => __E_cli_command_120(294).
	p(NT(293), (NT(294)));
//G417: cli_command(215)     => onf_cmd(293).
	p(NT(215), (NT(293)));
//G418: __E___E_cli_command_121_122(300) => 'd' 'e' 'f' 's'.
	p(NT(300), (T(55)+T(13)+T(42)+T(10)));
//G419: __E___E_cli_command_121_122(300) => 'd' 'e' 'f' 'i' 'n' 'i' 't' 'i' 'o' 'n' 's'.
	p(NT(300), (T(55)+T(13)+T(42)+T(15)+T(46)+T(15)+T(14)+T(15)+T(11)+T(46)+T(10)));
//G420: def_sym(299)         => __E___E_cli_command_121_122(300).
	p(NT(299), (NT(300)));
//G421: __E_cli_command_121(298) => def_sym(299).
	p(NT(298), (NT(299)));
//G422: def_list_cmd(297)    => __E_cli_command_121(298).
	p(NT(297), (NT(298)));
//G423: cli_command(215)     => def_list_cmd(297).
	p(NT(215), (NT(297)));
//G424: __E_cli_command_123(302) => def_sym(299) __(58) number(303).
	p(NT(302), (NT(299)+NT(58)+NT(303)));
//G425: def_print_cmd(301)   => __E_cli_command_123(302).
	p(NT(301), (NT(302)));
//G426: cli_command(215)     => def_print_cmd(301).
	p(NT(215), (NT(301)));
//G427: def_rr_cmd(304)      => rec_relation(16).
	p(NT(304), (NT(16)));
//G428: cli_command(215)     => def_rr_cmd(304).
	p(NT(215), (NT(304)));
//G429: qelim_sym(307)       => 'q' 'e' 'l' 'i' 'm'.
	p(NT(307), (T(53)+T(13)+T(18)+T(15)+T(12)));
//G430: __E_cli_command_124(306) => qelim_sym(307) __(58) wff_cmd_arg(308).
	p(NT(306), (NT(307)+NT(58)+NT(308)));
//G431: qelim_cmd(305)       => __E_cli_command_124(306).
	p(NT(305), (NT(306)));
//G432: cli_command(215)     => qelim_cmd(305).
	p(NT(215), (NT(305)));
//G433: get_sym(311)         => 'g' 'e' 't'.
	p(NT(311), (T(47)+T(13)+T(14)));
//G434: __E___E_cli_command_125_126(312) => __(58) option(313).
	p(NT(312), (NT(58)+NT(313)));
//G435: __E___E_cli_command_125_126(312) => null.
	p(NT(312), (nul));
//G436: __E_cli_command_125(310) => get_sym(311) __E___E_cli_command_125_126(312).
	p(NT(310), (NT(311)+NT(312)));
//G437: get_cmd(309)         => __E_cli_command_125(310).
	p(NT(309), (NT(310)));
//G438: cli_command(215)     => get_cmd(309).
	p(NT(215), (NT(309)));
//G439: set_sym(316)         => 's' 'e' 't'.
	p(NT(316), (T(10)+T(13)+T(14)));
//G440: __E___E_cli_command_127_128(317) => __(58).
	p(NT(317), (NT(58)));
//G441: __E___E_cli_command_127_128(317) => _(11) '=' _(11).
	p(NT(317), (NT(11)+T(3)+NT(11)));
//G442: __E_cli_command_127(315) => set_sym(316) __(58) option(313) __E___E_cli_command_127_128(317) option_value(318).
	p(NT(315), (NT(316)+NT(58)+NT(313)+NT(317)+NT(318)));
//G443: set_cmd(314)         => __E_cli_command_127(315).
	p(NT(314), (NT(315)));
//G444: cli_command(215)     => set_cmd(314).
	p(NT(215), (NT(314)));
//G445: toggle_sym(321)      => 't' 'o' 'g' 'g' 'l' 'e'.
	p(NT(321), (T(14)+T(11)+T(47)+T(47)+T(18)+T(13)));
//G446: __E_cli_command_129(320) => toggle_sym(321) __(58) bool_option(322).
	p(NT(320), (NT(321)+NT(58)+NT(322)));
//G447: toggle_cmd(319)      => __E_cli_command_129(320).
	p(NT(319), (NT(320)));
//G448: cli_command(215)     => toggle_cmd(319).
	p(NT(215), (NT(319)));
//G449: __E___E_cli_command_130_131(326) => 'h' 'i' 's' 't'.
	p(NT(326), (T(44)+T(15)+T(10)+T(14)));
//G450: __E___E_cli_command_130_131(326) => 'h' 'i' 's' 't' 'o' 'r' 'y'.
	p(NT(326), (T(44)+T(15)+T(10)+T(14)+T(11)+T(50)+T(20)));
//G451: history_sym(325)     => __E___E_cli_command_130_131(326).
	p(NT(325), (NT(326)));
//G452: __E_cli_command_130(324) => history_sym(325).
	p(NT(324), (NT(325)));
//G453: history_list_cmd(323) => __E_cli_command_130(324).
	p(NT(323), (NT(324)));
//G454: cli_command(215)     => history_list_cmd(323).
	p(NT(215), (NT(323)));
//G455: __E_cli_command_132(328) => history_sym(325) __(58) memory(329).
	p(NT(328), (NT(325)+NT(58)+NT(329)));
//G456: history_print_cmd(327) => __E_cli_command_132(328).
	p(NT(327), (NT(328)));
//G457: cli_command(215)     => history_print_cmd(327).
	p(NT(215), (NT(327)));
//G458: __E_cli_command_133(331) => wff(14).
	p(NT(331), (NT(14)));
//G459: __E_cli_command_133(331) => bf(21).
	p(NT(331), (NT(21)));
//G460: history_store_cmd(330) => __E_cli_command_133(331).
	p(NT(330), (NT(331)));
//G461: cli_command(215)     => history_store_cmd(330).
	p(NT(215), (NT(330)));
//G462: number(303)          => digits(152).
	p(NT(303), (NT(152)));
//G463: bf_cmd_arg(332)      => memory(329).
	p(NT(332), (NT(329)));
//G464: bf_cmd_arg(332)      => bf(21).
	p(NT(332), (NT(21)));
//G465: wff_cmd_arg(308)     => memory(329).
	p(NT(308), (NT(329)));
//G466: wff_cmd_arg(308)     => wff(14).
	p(NT(308), (NT(14)));
//G467: solve_cmd_arg(250)   => memory(329).
	p(NT(250), (NT(329)));
//G468: solve_cmd_arg(250)   => wff(14).
	p(NT(250), (NT(14)));
//G469: nf_cmd_arg(266)      => memory(329).
	p(NT(266), (NT(329)));
//G470: nf_cmd_arg(266)      => wff(14).
	p(NT(266), (NT(14)));
//G471: nf_cmd_arg(266)      => bf(21).
	p(NT(266), (NT(21)));
//G472: onf_cmd_arg(296)     => memory(329).
	p(NT(296), (NT(329)));
//G473: onf_cmd_arg(296)     => wff(14).
	p(NT(296), (NT(14)));
//G474: normalize_cmd_arg(261) => memory(329).
	p(NT(261), (NT(329)));
//G475: normalize_cmd_arg(261) => rr(10).
	p(NT(261), (NT(10)));
//G476: normalize_cmd_arg(261) => ref(18).
	p(NT(261), (NT(18)));
//G477: normalize_cmd_arg(261) => wff(14).
	p(NT(261), (NT(14)));
//G478: normalize_cmd_arg(261) => bf(21).
	p(NT(261), (NT(21)));
//G479: inst_args(271)       => wff_cmd_arg(308) _(11) '[' _(11) variable(111) _(11) '/' _(11) bf_cmd_arg(332) _(11) ']'.
	p(NT(271), (NT(308)+NT(11)+T(21)+NT(11)+NT(111)+NT(11)+T(56)+NT(11)+NT(332)+NT(11)+T(22)));
//G480: inst_args(271)       => bf_cmd_arg(332) _(11) '[' _(11) variable(111) _(11) '/' _(11) bf_cmd_arg(332) _(11) ']'.
	p(NT(271), (NT(332)+NT(11)+T(21)+NT(11)+NT(111)+NT(11)+T(56)+NT(11)+NT(332)+NT(11)+T(22)));
//G481: help_arg(232)        => help_sym(229).
	p(NT(232), (NT(229)));
//G482: help_arg(232)        => version_sym(222).
	p(NT(232), (NT(222)));
//G483: help_arg(232)        => quit_sym(219).
	p(NT(232), (NT(219)));
//G484: help_arg(232)        => clear_sym(225).
	p(NT(232), (NT(225)));
//G485: help_arg(232)        => get_sym(311).
	p(NT(232), (NT(311)));
//G486: help_arg(232)        => set_sym(316).
	p(NT(232), (NT(316)));
//G487: help_arg(232)        => toggle_sym(321).
	p(NT(232), (NT(321)));
//G488: help_arg(232)        => file_sym(235).
	p(NT(232), (NT(235)));
//G489: help_arg(232)        => history_sym(325).
	p(NT(232), (NT(325)));
//G490: help_arg(232)        => abs_memory_sym(333).
	p(NT(232), (NT(333)));
//G491: help_arg(232)        => rel_memory_sym(334).
	p(NT(232), (NT(334)));
//G492: help_arg(232)        => selection_sym(335).
	p(NT(232), (NT(335)));
//G493: help_arg(232)        => def_sym(299).
	p(NT(232), (NT(299)));
//G494: help_arg(232)        => inst_sym(269).
	p(NT(232), (NT(269)));
//G495: help_arg(232)        => subst_sym(264).
	p(NT(232), (NT(264)));
//G496: help_arg(232)        => normalize_sym(259).
	p(NT(232), (NT(259)));
//G497: help_arg(232)        => execute_sym(253).
	p(NT(232), (NT(253)));
//G498: help_arg(232)        => solve_sym(248).
	p(NT(232), (NT(248)));
//G499: help_arg(232)        => valid_sym(239).
	p(NT(232), (NT(239)));
//G500: help_arg(232)        => sat_sym(242).
	p(NT(232), (NT(242)));
//G501: help_arg(232)        => unsat_sym(245).
	p(NT(232), (NT(245)));
//G502: help_arg(232)        => dnf_sym(274).
	p(NT(232), (NT(274)));
//G503: help_arg(232)        => cnf_sym(277).
	p(NT(232), (NT(277)));
//G504: help_arg(232)        => anf_sym(280).
	p(NT(232), (NT(280)));
//G505: help_arg(232)        => snf_sym(292).
	p(NT(232), (NT(292)));
//G506: help_arg(232)        => nnf_sym(283).
	p(NT(232), (NT(283)));
//G507: help_arg(232)        => pnf_sym(286).
	p(NT(232), (NT(286)));
//G508: help_arg(232)        => mnf_sym(289).
	p(NT(232), (NT(289)));
//G509: help_arg(232)        => onf_sym(295).
	p(NT(232), (NT(295)));
//G510: help_arg(232)        => qelim_sym(307).
	p(NT(232), (NT(307)));
//G511: __E___E_help_arg_134_135(338) => 's'.
	p(NT(338), (T(10)));
//G512: __E___E_help_arg_134_135(338) => null.
	p(NT(338), (nul));
//G513: __E_help_arg_134(337) => 'e' 'x' 'a' 'm' 'p' 'l' 'e' __E___E_help_arg_134_135(338).
	p(NT(337), (T(13)+T(24)+T(17)+T(12)+T(54)+T(18)+T(13)+NT(338)));
//G514: examples_sym(336)    => __E_help_arg_134(337).
	p(NT(336), (NT(337)));
//G515: help_arg(232)        => examples_sym(336).
	p(NT(232), (NT(336)));
//G516: __E_memory_136(340)  => '%'.
	p(NT(340), (T(57)));
//G517: rel_memory_sym(334)  => '%' '-'.
	p(NT(334), (T(57)+T(25)));
//G518: memory_id(342)       => digits(152).
	p(NT(342), (NT(152)));
//G519: __E___E_memory_136_137(341) => memory_id(342).
	p(NT(341), (NT(342)));
//G520: __E___E_memory_136_137(341) => null.
	p(NT(341), (nul));
//G521: __E_memory_136(340)  => rel_memory_sym(334) __E___E_memory_136_137(341).
	p(NT(340), (NT(334)+NT(341)));
//G522: rel_memory(339)      => __E_memory_136(340).
	p(NT(339), (NT(340)));
//G523: memory(329)          => rel_memory(339).
	p(NT(329), (NT(339)));
//G524: abs_memory_sym(333)  => '%'.
	p(NT(333), (T(57)));
//G525: __E_memory_138(344)  => abs_memory_sym(333) memory_id(342).
	p(NT(344), (NT(333)+NT(342)));
//G526: abs_memory(343)      => __E_memory_138(344).
	p(NT(343), (NT(344)));
//G527: memory(329)          => abs_memory(343).
	p(NT(329), (NT(343)));
//G528: option(313)          => bool_option(322).
	p(NT(313), (NT(322)));
//G529: __E_option_139(347)  => 's' 'e' 'v'.
	p(NT(347), (T(10)+T(13)+T(51)));
//G530: __E_option_139(347)  => 's' 'e' 'v' 'e' 'r' 'i' 't' 'y'.
	p(NT(347), (T(10)+T(13)+T(51)+T(13)+T(50)+T(15)+T(14)+T(20)));
//G531: severity_opt(346)    => __E_option_139(347).
	p(NT(346), (NT(347)));
//G532: enum_option(345)     => severity_opt(346).
	p(NT(345), (NT(346)));
//G533: option(313)          => enum_option(345).
	p(NT(313), (NT(345)));
//G534: __E_bool_option_140(349) => 's'.
	p(NT(349), (T(10)));
//G535: __E_bool_option_140(349) => 's' 't' 'a' 't' 'u' 's'.
	p(NT(349), (T(10)+T(14)+T(17)+T(14)+T(48)+T(10)));
//G536: status_opt(348)      => __E_bool_option_140(349).
	p(NT(348), (NT(349)));
//G537: bool_option(322)     => status_opt(348).
	p(NT(322), (NT(348)));
//G538: __E_bool_option_141(351) => 'c'.
	p(NT(351), (T(45)));
//G539: __E_bool_option_141(351) => 'c' 'o' 'l' 'o' 'r'.
	p(NT(351), (T(45)+T(11)+T(18)+T(11)+T(50)));
//G540: __E_bool_option_141(351) => 'c' 'o' 'l' 'o' 'r' 's'.
	p(NT(351), (T(45)+T(11)+T(18)+T(11)+T(50)+T(10)));
//G541: colors_opt(350)      => __E_bool_option_141(351).
	p(NT(350), (NT(351)));
//G542: bool_option(322)     => colors_opt(350).
	p(NT(322), (NT(350)));
//G543: __E_bool_option_142(353) => 'd'.
	p(NT(353), (T(55)));
//G544: __E_bool_option_142(353) => 'd' 'b' 'g'.
	p(NT(353), (T(55)+T(49)+T(47)));
//G545: __E_bool_option_142(353) => 'd' 'e' 'b' 'u' 'g'.
	p(NT(353), (T(55)+T(13)+T(49)+T(48)+T(47)));
//G546: debug_repl_opt(352)  => __E_bool_option_142(353).
	p(NT(352), (NT(353)));
//G547: bool_option(322)     => debug_repl_opt(352).
	p(NT(322), (NT(352)));
//G548: option_value(318)    => option_value_true(354).
	p(NT(318), (NT(354)));
//G549: option_value(318)    => option_value_false(355).
	p(NT(318), (NT(355)));
//G550: option_value(318)    => severity(356).
	p(NT(318), (NT(356)));
//G551: option_value_true(354) => 't'.
	p(NT(354), (T(14)));
//G552: option_value_true(354) => 't' 'r' 'u' 'e'.
	p(NT(354), (T(14)+T(50)+T(48)+T(13)));
//G553: option_value_true(354) => 'o' 'n'.
	p(NT(354), (T(11)+T(46)));
//G554: option_value_true(354) => '1'.
	p(NT(354), (T(35)));
//G555: option_value_true(354) => 'y'.
	p(NT(354), (T(20)));
//G556: option_value_true(354) => 'y' 'e' 's'.
	p(NT(354), (T(20)+T(13)+T(10)));
//G557: option_value_false(355) => 'f'.
	p(NT(355), (T(42)));
//G558: option_value_false(355) => 'f' 'a' 'l' 's' 'e'.
	p(NT(355), (T(42)+T(17)+T(18)+T(10)+T(13)));
//G559: option_value_false(355) => 'o' 'f' 'f'.
	p(NT(355), (T(11)+T(42)+T(42)));
//G560: option_value_false(355) => '0'.
	p(NT(355), (T(36)));
//G561: option_value_false(355) => 'n'.
	p(NT(355), (T(46)));
//G562: option_value_false(355) => 'n' 'o'.
	p(NT(355), (T(46)+T(11)));
//G563: __E_severity_143(358) => 'e'.
	p(NT(358), (T(13)));
//G564: __E_severity_143(358) => 'e' 'r' 'r' 'o' 'r'.
	p(NT(358), (T(13)+T(50)+T(50)+T(11)+T(50)));
//G565: error_sym(357)       => __E_severity_143(358).
	p(NT(357), (NT(358)));
//G566: severity(356)        => error_sym(357).
	p(NT(356), (NT(357)));
//G567: __E_severity_144(360) => 'i'.
	p(NT(360), (T(15)));
//G568: __E_severity_144(360) => 'i' 'n' 'f' 'o'.
	p(NT(360), (T(15)+T(46)+T(42)+T(11)));
//G569: info_sym(359)        => __E_severity_144(360).
	p(NT(359), (NT(360)));
//G570: severity(356)        => info_sym(359).
	p(NT(356), (NT(359)));
//G571: __E_severity_145(362) => 'd'.
	p(NT(362), (T(55)));
//G572: __E_severity_145(362) => 'd' 'e' 'b' 'u' 'g'.
	p(NT(362), (T(55)+T(13)+T(49)+T(48)+T(47)));
//G573: debug_sym(361)       => __E_severity_145(362).
	p(NT(361), (NT(362)));
//G574: severity(356)        => debug_sym(361).
	p(NT(356), (NT(361)));
//G575: __E_severity_146(364) => 't'.
	p(NT(364), (T(14)));
//G576: __E_severity_146(364) => 't' 'r' 'a' 'c' 'e'.
	p(NT(364), (T(14)+T(50)+T(17)+T(45)+T(13)));
//G577: trace_sym(363)       => __E_severity_146(364).
	p(NT(363), (NT(364)));
//G578: severity(356)        => trace_sym(363).
	p(NT(356), (NT(363)));
	#undef T
	#undef NT
	return loaded = true, p;
}

inline ::idni::grammar<char_type, terminal_type> grammar(
	nts, productions(), start_symbol, char_classes, grammar_options);

} // namespace tau_parser_data

struct tau_parser : public idni::parser<char, char> {
	enum nonterminal {
		nul, eof, space, digit, xdigit, alpha, alnum, punct, printable, start, 
		rr, _, rec_relations, main, wff, __E_rec_relations_0, rec_relation, __E_rec_relations_1, ref, __E_rec_relation_2, 
		capture, bf, sym, __E_ref_3, offsets, ref_args, __E_ref_args_4, __E___E_ref_args_4_5, ref_arg, __E___E_ref_args_4_6, 
		__E___E_ref_args_4_7, inputs, __E_inputs_8, __E_inputs_9, input, in, source_binding, library, rules, __E_library_10, 
		__E___E_library_10_11, rule, __E___E___E_library_10_11_12, wff_rule, bf_rule, __E___E_library_10_13, wff_matcher, wff_body, __E_wff_rule_14, wff_cb, 
		bf_matcher, bf_body, __E_bf_rule_15, bf_cb, builder, builder_head, builder_body, __E_builder_head_16, __, __E_builder_head_17, 
		bf_builder_body, __E_builder_body_18, wff_builder_body, __E_builder_body_19, wff_parenthesis, __E_wff_20, wff_sometimes, __E_wff_21, __E___E_wff_21_22, wff_always, 
		__E_wff_23, __E___E_wff_23_24, wff_conditional, __E_wff_25, wff_all, __E_wff_26, q_vars, wff_ex, __E_wff_27, wff_ref, 
		wff_imply, __E_wff_28, wff_equiv, __E_wff_29, wff_or, __E_wff_30, wff_xor, __E_wff_31, wff_and, __E_wff_32, 
		wff_neg, __E_wff_33, wff_t, wff_f, bf_interval, __E_wff_34, bf_neq, __E_wff_35, bf_eq, __E_wff_36, 
		bf_nleq, __E_wff_37, bf_greater, __E_wff_38, bf_less_equal, __E_wff_39, bf_less, __E_wff_40, uninterpreted_constant, bf_parenthesis, 
		__E_bf_41, variable, bf_splitter, __E_bf_42, bf_ref, bf_or, __E_bf_43, bf_xor, __E_bf_44, bf_and, 
		__E_bf_45, __E___E_bf_45_46, bf_neg, __E_bf_47, bf_constant, __E_bf_48, constant, bf_t, bf_f, flag, 
		flag_neq, __E_flag_49, flagvar, num, flag_eq, __E_flag_50, flag_greater_equal, __E_flag_51, flag_greater, __E_flag_52, 
		flag_less_equal, __E_flag_53, flag_less, __E_flag_54, charvar, __E_charvar_55, __E_charvar_56, io_var, __E_variable_57, out, 
		in_var_name, __E_in_58, digits, offset, out_var_name, __E_out_59, q_var, __E_q_vars_60, __E_q_vars_61, __E_offsets_62, 
		__E_offsets_63, shift, __E_offset_64, __E_shift_65, __E___E_shift_65_66, uninter_const_name, __E_uninterpreted_constant_67, __E___E_uninterpreted_constant_67_68, chars, binding, 
		__E_binding_69, type, __E___E_binding_69_70, source, named_binding, src_c, __E_source_71, __E___E_source_71_72, __E___E_source_71_73, __E_src_c_74, 
		__E_src_c_75, __E_chars_76, __E_digits_77, extra, comment, __E_comment_78, __E_comment_79, __E_comment_80, __E____81, __E___82, 
		bf_cb_args1, bf_cb_arg, bf_cb_args2, bf_cb_args3, bf_cb_args4, wff_cb_args1, wff_cb_arg, wff_cb_args2, wff_cb_args3, wff_cb_args4, 
		wff_has_clashing_subformulas_cb, __E_wff_cb_83, wff_has_subformula_cb, __E_wff_cb_84, wff_remove_existential_cb, __E_wff_cb_85, bf_has_subformula_cb, __E_bf_cb_86, bf_remove_funiversal_cb, __E_bf_cb_87, 
		bf_remove_fexistential_cb, __E_bf_cb_88, bf_normalize_cb, __E_bf_cb_89, cli, cli_command, __E_cli_90, __E_cli_91, quit_cmd, quit_sym, 
		__E_cli_command_92, version_cmd, version_sym, __E_cli_command_93, clear_cmd, clear_sym, __E_cli_command_94, help_cmd, __E_cli_command_95, help_sym, 
		__E___E_cli_command_95_96, __E___E_cli_command_95_97, help_arg, file_cmd, __E_cli_command_98, file_sym, q_string, valid_cmd, __E_cli_command_99, valid_sym, 
		sat_cmd, __E_cli_command_100, sat_sym, unsat_cmd, __E_cli_command_101, unsat_sym, solve_cmd, __E_cli_command_102, solve_sym, __E___E_cli_command_102_103, 
		solve_cmd_arg, execute_cmd, __E_cli_command_104, execute_sym, __E___E_cli_command_104_105, __E___E_cli_command_104_106, wff_typed, normalize_cmd, __E_cli_command_107, normalize_sym, 
		__E___E_cli_command_107_108, normalize_cmd_arg, subst_cmd, __E_cli_command_109, subst_sym, __E___E_cli_command_109_110, nf_cmd_arg, inst_cmd, __E_cli_command_111, inst_sym, 
		__E___E_cli_command_111_112, inst_args, dnf_cmd, __E_cli_command_113, dnf_sym, cnf_cmd, __E_cli_command_114, cnf_sym, anf_cmd, __E_cli_command_115, 
		anf_sym, nnf_cmd, __E_cli_command_116, nnf_sym, pnf_cmd, __E_cli_command_117, pnf_sym, mnf_cmd, __E_cli_command_118, mnf_sym, 
		snf_cmd, __E_cli_command_119, snf_sym, onf_cmd, __E_cli_command_120, onf_sym, onf_cmd_arg, def_list_cmd, __E_cli_command_121, def_sym, 
		__E___E_cli_command_121_122, def_print_cmd, __E_cli_command_123, number, def_rr_cmd, qelim_cmd, __E_cli_command_124, qelim_sym, wff_cmd_arg, get_cmd, 
		__E_cli_command_125, get_sym, __E___E_cli_command_125_126, option, set_cmd, __E_cli_command_127, set_sym, __E___E_cli_command_127_128, option_value, toggle_cmd, 
		__E_cli_command_129, toggle_sym, bool_option, history_list_cmd, __E_cli_command_130, history_sym, __E___E_cli_command_130_131, history_print_cmd, __E_cli_command_132, memory, 
		history_store_cmd, __E_cli_command_133, bf_cmd_arg, abs_memory_sym, rel_memory_sym, selection_sym, examples_sym, __E_help_arg_134, __E___E_help_arg_134_135, rel_memory, 
		__E_memory_136, __E___E_memory_136_137, memory_id, abs_memory, __E_memory_138, enum_option, severity_opt, __E_option_139, status_opt, __E_bool_option_140, 
		colors_opt, __E_bool_option_141, debug_repl_opt, __E_bool_option_142, option_value_true, option_value_false, severity, error_sym, __E_severity_143, info_sym, 
		__E_severity_144, debug_sym, __E_severity_145, trace_sym, __E_severity_146, __N_0, __N_1, __N_2, __N_3, __N_4, 
		__N_5, 
	};
	static tau_parser& instance() {
		static tau_parser inst;
		return inst;
	}
	tau_parser() : idni::parser<char_type, terminal_type>(
		tau_parser_data::grammar,
		tau_parser_data::parser_options) {}
	size_t id(const std::basic_string<char_type>& name) {
		return tau_parser_data::nts.get(name);
	}
	const std::basic_string<char_type>& name(size_t id) {
		return tau_parser_data::nts.get(id);
	}
	symbol_type literal(const nonterminal& nt) {
		return symbol_type(nt, &tau_parser_data::nts);
	}
};

#endif // __TAU_PARSER_H__

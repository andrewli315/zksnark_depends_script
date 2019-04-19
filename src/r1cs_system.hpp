#ifndef R1CS_SYSTEM_HPP_
#define R1CS_SYSTEM_HPP_

#include <cassert>
#include <libsnark/relations/constraint_satisfaction_problems/r1cs/r1cs.hpp>
#include <libff/common/utils.hpp>


namespace libsnark{

template<typename FieldT>
struct r1cs_system {
	r1cs_constraint_system<FieldT> constraint_system;
	r1cs_primary_input<FieldT> primary_input;
	r1cs_auxiliary_input<FieldT> auxiliary_input;

	r1cs_system<FieldT>() = default;
	r1cs_system<FieldT>(const r1cs_system<FieldT> &other) = default;
	r1cs_system<FieldT>(const r1cs_constraint_system<FieldT> &constraint_system,
						const r1cs_primary_input<FieldT> &primary_input,
						const r1cs_auxiliary_input<FieldT> &auxiliary_input):
		constraint_system(constraint_system),
		primary_input(primary_input),
		auxiliary_input(auxiliary_input)
	{};

	r1cs_system<FieldT>(const r1cs_constraint_system<FieldT> &&constraint_system,
						const r1cs_primary_input<FieldT> &&primary_input,
						const r1cs_auxiliary_input<FieldT> &&auxiliary_input):
		constraint_system(constraint_system),
		primary_input(primary_input),
		auxiliary_input(auxiliary_input)
	{};
};

/* 	
	Generate R1CS constraint system
*/
template<typename FieldT>
r1cs_system<FieldT> generate_r1cs_system_with_field_input(const size_t num_constraints,
                                                     const size_t num_inputs);

template<typename FieldT>
r1cs_system<FieldT> generate_r1cs_system_with_binary_input(const size_t num_constraints,
                                                           const size_t num_inputs);
}

#include "r1cs_system.tcc"

#endif

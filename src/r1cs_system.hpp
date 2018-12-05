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
r1cs_system<FieldT> generate_system_with_field(const size_t num_constraints,
												const size_t num_inputs)
{
	// num_constraints >= num_inputs-2
	assert(num_inputs <= num_constraints + 2);
	r1cs_constraint_system<FieldT> cs;
	cs.primary_input_size = num_inputs;
	cs.auxiliary_input_size = 2 + num_constraints - num_inputs;

	r1cs_variable_assignment<FieldT> full_variable_assignment;
	FieldT a = FieldT::random_element();
	FieldT b = FieldT::random_element();
	full_variable_assignment.push_back(a);
	full_variable_assignment.push_back(b);

	for(size_t i = 0; i < num_constraints - 1; ++i)
	{
		linear_combination<FieldT> A, B, C;
		if( i % 2 )
		{
			// a * b = c
			A.add_term(i+1,1);
			B.add_term(i+2,1);
			C.add_term(i+3,1);
			FieldT tmp = a * b;
			full_variable_assignment.push_back(tmp);
			a = b; b = tmp;
		}
		else
		{
			// a + b = c
			B.add_term(0,1);
			A.add_term(i+1,1);
			A.add_term(i+2,1);
			C.add_term(i+3,1);
			FieldT tmp = a + b;
			full_variable_assignment.push_back(tmp);
			a = b; b = tmp;
		}
		cs.add_constraint(r1cs_constraint<FieldT>(A, B, C));
	}
	linear_combination<FieldT> A, B, C;
	FieldT fin = FieldT::zero();
	for(size_t i = 0; i < cs.num_variables(); ++i)
	{
		A.add_term(i,1);
		B.add_term(i,1);
		fin = fin + full_variable_assignment[i-1];
	}
	C.add_term(cs.num_variables(), 1);
	cs.add_constraint(r1cs_constraint<FieldT>(A, B, C));
	full_variable_assignment.push_back(fin.squared());

	/* split variable assignment*/
	r1cs_primary_input<FieldT> primary_input(full_variable_assignment.begin(),
							full_variable_assignment.begin()+num_inputs);
	r1cs_primary_input<FieldT> auxiliary_input(full_variable_assignment.begin()+num_inputs,
							full_variable_assignment.end());
	/* sanity check */

	assert(cs.num_variables() == full_variable_assignment.size());
	assert(cs.num_variables() >= num_inputs);
	assert(cs.num_inputs() == num_inputs);
	assert(cs.num_constraints() == num_constraints);
	assert(cs.is_satisfied(primary_input, auxiliary_input));

	std::cout << std::endl << "Generating system finished" << std::endl << "Check pass";
	
	return r1cs_system<FieldT>(std::move(cs), std::move(primary_input), std::move(auxiliary_input));

}
template<typename FieldT>
r1cs_system<FieldT> generate_system_with_binary(const size_t num_constraints,
												const size_t num_inputs)
{

}

}

#endif

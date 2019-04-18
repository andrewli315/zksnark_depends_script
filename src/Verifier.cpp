#include "Verifier.hpp"

using namespace std;
template<typename FieldT>
Verifier<FieldT>::Verifier()
{
	this->vk = NULL;
	this->primary_input = NULL;
	this->proof = NULL;
}

template<typename FieldT>
Verifier<FieldT>::Verifier(r1cs_gg_ppzksnark_verification_key<FieldT> vk,
		r1cs_gg_ppzksnark_primary_input<FieldT> primary_input,
		r1cs_gg_ppzksnark_proof<FieldT> proof)
{
	this->proof = proof;
	this->primary_input = primary_input;
	this->vk = vk;
}
template<typename FieldT>
void Verifier<FieldT>::set_vk(r1cs_gg_ppzksnark_verification_key<FieldT> vk)
{
	this->vk = vk;
}
template<typename FieldT>
void Verifier<FieldT>::set_primary_input(r1cs_gg_ppzksnark_primary_input<FieldT> primary_input)
{
	this->primary_input = primary_input;
}

template<typename FieldT>
void Verifier<FieldT>::set_proof(r1cs_gg_ppzksnark_proof<FieldT> proof)
{
	this->proof = proof;
}

template<typename FieldT>
bool Verifier<FieldT>::verify()
{
	bool ret = false;
	ret = r1cs_gg_ppzksnark_verifier_strong_IC<FieldT>( this->vk, this->primary_input, this->proof);
	return ret;
}


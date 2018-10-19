#ifndef __H_CHAINSQL_CONTRACT_HELPER_H__
#define __H_CHAINSQL_CONTRACT_HELPER_H__

#include <vector>
#include <ripple/protocol/STTx.h>
#include <ripple/basics/TaggedCache.h>
#include <ripple/json/json_value.h>
#include <ripple/basics/base_uint.h>
#include <ripple/app/main/Application.h>

namespace ripple {

class ContractHelper
{
public:
	ContractHelper(Application& app);

	
	//new tx when smart contract executing
	void addTx(uint256 const& txHash, STTx const& tx);
	std::vector<STTx> getTxsByHash(uint256 const& txHash);

	//for get interface
	void addRecord(uint256 const& handle, Json::Value const& result);
	Json::Value getRecord(uint256 const& handle);
	void releaseHandle(uint256 const& handle);

private:
	TaggedCache<uint256, std::vector<STTx>>	mTxCache;
	TaggedCache<uint256, Json::Value>		mRecordCache;
	Application&							app_;
};

}
#endif
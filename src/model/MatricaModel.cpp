#include "model/MatricaModel.h"

#include <algorithm>

namespace matrica {

	/**
	* \class jci::MatricaModel
	*/
	MatricaModel::MatricaModel() {
	}

	MatricaModel::MatricaModel( const int id, const int xRes, const int yRes, const int divisor, const std::string& Channel, const TriggerableVisual::VisualType& visType, const ci::Color& main, const ci::Color& accent, const ci::Color& high)
		: mChannel(Channel)
		, mMainColor(main)
		, mAccentColor(accent)
		, mHighlightColor(high)
		, mXRes(xRes)
		, mYRes(yRes)
		, mVisualType(visType)
		, mId(id)
		, mDivisor(divisor)
	{
	}

	void MatricaModel::clear() {
		mChannel.clear();

	}

	bool MatricaModel::empty() const {
		return mChannel.empty();
	}

	void MatricaModel::swap(MatricaModel& o) {
		if (this != &o) {
			mChannel.swap(o.mChannel);
		}
	}

	const int& MatricaModel::getId() const {
		return mId;
	}

	const int& MatricaModel::getXRes() const {
		return mXRes;
	}

	const int& MatricaModel::getYRes() const {
		return mYRes;
	}

	const int& MatricaModel::getDivisor() const {
		return mDivisor;
	}

	const std::string& MatricaModel::getChannel() const {
		return mChannel;
	}

	const ci::Color&		MatricaModel::getMainColor() const {
		return mMainColor;
	}

	const ci::Color&		MatricaModel::getAccentColor() const {
		return mAccentColor;
	}
	
	const ci::Color&		MatricaModel::getHighlightColor() const {
		return mHighlightColor;
	}

	const TriggerableVisual::VisualType&	MatricaModel::getVisualType() const{
		return mVisualType;
	}


} // namespace matrica

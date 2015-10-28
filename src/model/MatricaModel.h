#pragma once
#ifndef MATRICA_MODEL_MATRICA_MODEL_H_
#define MATRICA_MODEL_MATRICA_MODEL_H_

#include <string>
#include <cinder/Color.h>
#include "visuals/triggerable_visual.h"

namespace matrica {

	/**
	* \class matrica::MatricaModel
	* \brief The model for a "Matrica" includes information about the channel, color, and size of the panel.
	*/
	class MatricaModel
	{
	public:
		MatricaModel();
		MatricaModel(const int xRes, const int yRes, const std::string& Channel, const TriggerableVisual::VisualType& visType, const ci::Color& main, const ci::Color& accent, const ci::Color& high);

		void					clear();
		bool					empty() const;
		void					swap(MatricaModel&);

		const int&				getXRes() const;
		const int&				getYRes() const;
		const std::string&		getChannel() const;
		const ci::Color&		getMainColor() const;
		const ci::Color&		getAccentColor() const;
		const ci::Color&		getHighlightColor() const;

		const TriggerableVisual::VisualType& getVisualType() const;

	private:

		std::string			mChannel;

		ci::Color			mMainColor;
		ci::Color			mAccentColor;
		ci::Color			mHighlightColor;

		TriggerableVisual::VisualType mVisualType;

		int					mXRes;
		int					mYRes;

	};

} // namespace matrica

#endif // 

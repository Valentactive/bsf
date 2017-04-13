//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Marko Pintera (marko.pintera@gmail.com). All rights reserved. **********************//
#pragma once

#include "BsCorePrerequisites.h"
#include "BsSkybox.h"
#include "BsComponent.h"

namespace bs
{
	/** @addtogroup Components
	 *  @{
	 */

	/**
	 * @copydoc	Skybox
	 *
	 * @note	Wraps Skybox as a Component.
	 */
	class BS_CORE_EXPORT BS_SCRIPT_EXPORT(n:Skybox) CSkybox : public Component
	{
	public:
		CSkybox(const HSceneObject& parent);
		virtual ~CSkybox();

		/** @copydoc Skybox::getTexture */
		BS_SCRIPT_EXPORT(n:Texture,pr:getter)
		HTexture getTexture() const { return mInternal->getTexture(); }

		/** @copydoc Skybox::setTexture */
		BS_SCRIPT_EXPORT(n:Texture,pr:setter)
		void setTexture(const HTexture& texture) { mInternal->setTexture(texture); }

		/** @copydoc Skybox::setBrightness */
		BS_SCRIPT_EXPORT(n:Brightness,pr:setter)
		void setBrightness(float brightness) { mInternal->setBrightness(brightness); }

		/** @copydoc Skybox::getBrightness */
		BS_SCRIPT_EXPORT(n:Brightness,pr:getter)
		float getBrightness() const { return mInternal->getBrightness(); }

		/** @name Internal
		 *  @{
		 */

		/**	Returns the skybox that this component wraps. */
		SPtr<Skybox> _getSkybox() const { return mInternal; }

		/** @} */

	protected:
		mutable SPtr<Skybox> mInternal;

		/************************************************************************/
		/* 						COMPONENT OVERRIDES                      		*/
		/************************************************************************/
	protected:
		friend class SceneObject;

		/** @copydoc Component::onInitialized */
		void onInitialized() override;

		/** @copydoc Component::update */
		void update() override { }

		/************************************************************************/
		/* 								RTTI		                     		*/
		/************************************************************************/
	public:
		friend class CSkyboxRTTI;
		static RTTITypeBase* getRTTIStatic();
		RTTITypeBase* getRTTI() const override;

	protected:
		CSkybox(); // Serialization only
	};

	/** @} */
}
#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
class SceneNode : public sf::Transformable, public sf::Drawable,
	private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;
	SceneNode();
	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);
	~SceneNode();
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
private:
	std::vector<Ptr> mChildren;
	SceneNode* mParent;
};


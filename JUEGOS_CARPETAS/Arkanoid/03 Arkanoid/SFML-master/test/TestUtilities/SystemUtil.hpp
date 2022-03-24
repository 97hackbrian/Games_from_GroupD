// Header for SFML unit tests.
//
// For a new system module test case, include this header.
// This ensures that string conversions are visible and can be used by doctest for debug output.

#ifndef SFML_TESTUTILITIES_SYSTEM_HPP
#define SFML_TESTUTILITIES_SYSTEM_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>

#include <ostream>
#include <sstream>
#include <string>

// String conversions for doctest framework
namespace sf
{
    class Angle;
    class String;
    class Time;

    std::ostream& operator <<(std::ostream& os, const sf::Angle& angle);
    std::ostream& operator <<(std::ostream& os, const sf::String& string);
    std::ostream& operator <<(std::ostream& os, sf::Time time);

    template <typename T>
    std::ostream& operator <<(std::ostream& os, const sf::Vector2<T>& vector)
    {
        os << "(" << vector.x << ", " << vector.y << ")";
        return os;
    }

    template <typename T>
    std::ostream& operator <<(std::ostream& os, const sf::Vector3<T>& vector)
    {
        os << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
        return os;
    }
}

// Utilities for approximate equality
struct ApproxVec
{
    ApproxVec(double x, double y)
        : vector(static_cast<float>(x), static_cast<float>(y)) {}

    explicit ApproxVec(const sf::Vector2f& v)
        : vector(v) {}

    sf::Vector2f vector;
};

// Utilities for approximate equality
struct ApproxDeg
{
    ApproxDeg(double degrees)
        : degrees(static_cast<float>(degrees)) {}

    float degrees;
};

bool operator==(const sf::Vector2f& lhs, const ApproxVec& rhs);
bool operator==(const sf::Angle& lhs, const ApproxDeg& rhs);

std::ostream& operator <<(std::ostream& os, const ApproxVec& approx);
std::ostream& operator <<(std::ostream& os, const ApproxDeg& approx);

namespace sf::Testing
{
    class TemporaryFile
    {
    private:
        std::string m_path;

    public:
        // Create a temporary file with a randomly generated path, containing 'contents'.
        TemporaryFile(const std::string& contents);

        // Close and delete the generated file.
        ~TemporaryFile();

        // Prevent copies.
        TemporaryFile(const TemporaryFile&) = delete;
        TemporaryFile& operator=(const TemporaryFile&) = delete;

        // Return the randomly generated path.
        const std::string& getPath() const;
    };
}

#endif // SFML_TESTUTILITIES_SYSTEM_HPP

// Generated by gencpp from file rclock/logDirResponse.msg
// DO NOT EDIT!


#ifndef RCLOCK_MESSAGE_LOGDIRRESPONSE_H
#define RCLOCK_MESSAGE_LOGDIRRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rclock
{
template <class ContainerAllocator>
struct logDirResponse_
{
  typedef logDirResponse_<ContainerAllocator> Type;

  logDirResponse_()
    : directory()  {
    }
  logDirResponse_(const ContainerAllocator& _alloc)
    : directory(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _directory_type;
  _directory_type directory;




  typedef boost::shared_ptr< ::rclock::logDirResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rclock::logDirResponse_<ContainerAllocator> const> ConstPtr;

}; // struct logDirResponse_

typedef ::rclock::logDirResponse_<std::allocator<void> > logDirResponse;

typedef boost::shared_ptr< ::rclock::logDirResponse > logDirResponsePtr;
typedef boost::shared_ptr< ::rclock::logDirResponse const> logDirResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rclock::logDirResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rclock::logDirResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rclock

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/jade/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rclock::logDirResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rclock::logDirResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rclock::logDirResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rclock::logDirResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rclock::logDirResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rclock::logDirResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rclock::logDirResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "310e138069b8368226f05a8c4e7bb107";
  }

  static const char* value(const ::rclock::logDirResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x310e138069b83682ULL;
  static const uint64_t static_value2 = 0x26f05a8c4e7bb107ULL;
};

template<class ContainerAllocator>
struct DataType< ::rclock::logDirResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rclock/logDirResponse";
  }

  static const char* value(const ::rclock::logDirResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rclock::logDirResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string directory\n\
\n\
";
  }

  static const char* value(const ::rclock::logDirResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rclock::logDirResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.directory);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct logDirResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rclock::logDirResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rclock::logDirResponse_<ContainerAllocator>& v)
  {
    s << indent << "directory: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.directory);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RCLOCK_MESSAGE_LOGDIRRESPONSE_H
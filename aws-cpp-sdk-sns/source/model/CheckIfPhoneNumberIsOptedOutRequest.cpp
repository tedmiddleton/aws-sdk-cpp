﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/sns/model/CheckIfPhoneNumberIsOptedOutRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::SNS::Model;
using namespace Aws::Utils;

CheckIfPhoneNumberIsOptedOutRequest::CheckIfPhoneNumberIsOptedOutRequest() : 
    m_phoneNumberHasBeenSet(false)
{
}

Aws::String CheckIfPhoneNumberIsOptedOutRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=CheckIfPhoneNumberIsOptedOut&";
  if(m_phoneNumberHasBeenSet)
  {
    ss << "phoneNumber=" << StringUtils::URLEncode(m_phoneNumber.c_str()) << "&";
  }

  ss << "Version=2010-03-31";
  return ss.str();
}


void  CheckIfPhoneNumberIsOptedOutRequest::DumpBodyToUrl(Aws::Http::URI& uri ) const
{
  uri.SetQueryString(SerializePayload());
}

#include "fp_acl.h"

bool fp_acl_check_system_permissions(struct fp_acl_settings* settings, uint32_t requiredPermissions)
{
    if ((settings->systemPermissions & requiredPermissions) == requiredPermissions) {
        return true;
    }
    return false;
}

bool fp_acl_check_user_permissions(struct fp_acl_user* user, bool isLocal, uint32_t requiredPermissions)
{
    if (isLocal) {
        requiredPermissions |= FP_ACL_PERMISSION_LOCAL_ACCESS;
    } else {
        requiredPermissions |= FP_ACL_PERMISSION_REMOTE_ACCESS;
    }
    
    if ((user->permissions & requiredPermissions) == requiredPermissions) {
        return true;
    }
    return false;
}

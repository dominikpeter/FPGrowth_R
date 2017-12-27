
#' @export
create_transactions <- function(df, id, item){
  split.data.frame(df,id) %>%
    lapply("[[",item)
}
